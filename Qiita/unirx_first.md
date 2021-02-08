# UniRxのFirstオペレータを使ったらInvalidOperationException: sequence is empty

## 経緯

UIに一定時間触れないと自動で消えてくれるようにしてくれ！と言われたのでこんなコードを書いた。

```
private float _lastTime;
private float lifespan;
private void OnEnable()
{
    this.UpdateAsObservable()
        .First(_ => Time.unscaledTime - _lastTime > lifespan)
        .Subscribe(_ =>
        {
            // UIが消える処理
        });
}
```

できたできたと思っていたら、`シーンから離れるとエラーになる`と言われた。

```
InvalidOperationException: sequence is empty
```

## AddTo忘れてた！

ちゃんと購読中止するの忘れてた、と思ったので`.AddTo(this)`を追加

```
private float _lastTime;
private float lifespan;
private void OnEnable()
{
    this.UpdateAsObservable()
        .First(_ => Time.unscaledTime - _lastTime > lifespan)
        .Subscribe(_ =>
        {
            // UIが消える処理
        })
        .AddTo(this);
}
```

それでもエラーは解消されない。

```
InvalidOperationException: sequence is empty
```

そもそも`UpdateAsObservable`はオブジェクトの破棄時に自動でDisposeしてくれるらしい
[参考](https://qiita.com/toRisouP/items/30c576c7b0a99f41fb87#updateasobservableとobservableeveryupdateの使い分け)
めっちゃ便利ですね。

## FirstはOnNextを発行しなければならない

どうやら`First`オペレータは値を発行する前に`OnCompleted()`しようとすると怒るらしい。
UniRxのソースコードは次のようになっている。

```
public override void OnCompleted()
{
    if (parent.`useDefault`)
    {
        if (notPublished)
        {
            observer.OnNext(default(T));
        }
        try { observer.OnCompleted(); }
        finally { Dispose(); }
    }
    else
    {
        if (notPublished)
        {
            try { observer.OnError(new InvalidOperationException("sequence is empty")); }
            finally { Dispose(); }
        }
        else
        {
            try { observer.OnCompleted(); }
            finally { Dispose(); }
        }
    }
}
```
`useDefault`が`false`かつ`notPublished`が`true`だと冒頭のエラーを吐くようになっていることがわかる。
`notPublished`は`OnNext()`の中で`false`にセットされる。
`First`オペレータは`useDefault`が`false`となってしまうので、値を発行する前に`Dispose`しようとする（今回はシーン移動によるオブジェクトの破棄がきっかけ）とエラーとなってしまう。

## 対策

`FirstOrDefault`を使用する！
これで`useDefault`がtrueとなり、`OnNext()`を呼ぶ前であってもDefaultの値を発行した後、正しく購読中止される。

↓が完成形のコード

```
private void OnEnable()
{
    _lastTime = CurrentTime();
    this.UpdateAsObservable()
        .FirstOrDefault(_ => Time.unscaledTime - _lastTime > lifespan)
        .Subscribe(_ =>
        {
            // UIを消す処理
        });
}

```
