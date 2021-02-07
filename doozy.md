# DoozyUIの使い方

1. Canvasをデータベースに登録
2. Canvasオブジェクトを作成
3. ボタンをデータベースに登録
4. Graphを作成
5. GraphのNodeを作成
6. Nodeを開く
   1. 名前を変える
   2. ノードから離れる条件を設定（例: ボタンのクリック）
   3. 他のノードとConnectionを貼って遷移を規定する
   4. OnEnterNode(入ったときに行う処理)とOnExitNode(出たときに行う処理)を書く
      1. UIViewの切り替えとか
7. UIViewのShow, Hideのアニメーションを設定する
   1. Play Start AnimationのCustom Start Pointに注意
   2. Custom From & Toを利用するとうまくいくことがある
