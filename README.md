# so_long_group1
42tokyoの課題で、C言語で2Dゲームを作成しました。

（コンパイル手順）　
１：macOSの方は、まずXquartzを起動してください。
２：so_longディレクトリでmakeコマンドを実行していただくと、so_longという実行ファイルが作成されます

(実行方法)
./so_long マップファイル

マップファイルは、map/, maps/にあります。
"maps/map_OK0*"を指定ください。
"maps/map_NG0*"はマップとしての条件を満たしていないファイルです。

マップtxtファイルで自由に作れます。
・'0':地面
・'1':壁
・'E':ゴール
・'C':コイン
・'P':プレイヤー
「プレイできるマップの条件」
・P, Eは１つだけ
・マップは長方形で、全てのへんが1(壁)で囲まれていないといけない