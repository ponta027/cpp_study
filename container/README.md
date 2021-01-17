# container


## STL

* [STL](https://ja.wikipedia.org/wiki/Standard_Template_Library)
    * Standard Template Library

よく使用されるアルゴリズムとデータ構造を実装したクラステンプレート及び関数テンプレートの集合
STLを使用することにより車輪の再開発をしなくてすむようになる。

* STLの構成要素
    * container
    * algorithm
    * iterator
    * allocator
    * function object
    * adapter

コンテナはデータを実際に格納するコンポーネント

| container         | desc |
|-------------------|----------------------------| 
| dequeu            | 両端から操作できるキュー       |
| list              | 線形リスト                   |
| map               | キーのと値のペアを格納するコンテナ。１つのキーは１つの値に対応する。|
| multimap          | キーと値のペアを格納するコンテナ。１つのキーが複数の値に対応する。|
| multiset          | 要素の重複が許可される集合  |
| priority_queue    | 優先順位付きキュー|
| queue             | キュー           |
| set               | 要素の重複が許されない集合 |
| stack             | スタック | 
| vector            | 動的配列   |


* [vector sample](/container/src/vector.cpp)
* [map sample](/container/src/map.cpp)



以上
