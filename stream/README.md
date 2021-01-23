# stream

https://ja.wikipedia.org/wiki/%E3%82%B9%E3%83%88%E3%83%AA%E3%83%BC%E3%83%A0_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#%E5%85%A5%E5%87%BA%E5%8A%9B%E3%82%B9%E3%83%88%E3%83%AA%E3%83%BC%E3%83%A0)

連続データ＝流れ(stream)として捉えて、そのデータの入出力/送受信を扱うこと。
その操作の抽象データ型を指す。

C言語やUnixだと標準ストリーム（標準入力、標準エラー、標準出力）が用意されている。
すべてファイルストリームとして抽象化されている。ファイルポインタで扱うことが可能。

Streamの種類としては以下が存在する。

* istream
* ostream
* ifstream
* ofstream
* istringstream
* ostringstream

```

ios_base <|--- ios
ios <|---- istream
ios <|---- ostream
istream <|---- iostream
ostream <|-----iostream

istream <|---- istringstream
ostream <|-----ostreamstream
iostream <|----stringstream

istream <|-----ifstream
ostream <|-----ofstream

istream <|------fstream
ostream <|------fstream

```

## Input Stream

入力が可能なストリーム（fstream、ifstream、stringstream、istringstream、iostream、istream）

* function
   * <<
   * get,read
   * etc....


## OutPut Stream

出力が可能なストリーム（fstream、ofstream、stringstream、ostringstream、iostream、ostream）

* function
   * >>
   * put,write
   * etc....


## String Stream

C++では文字列操作をstringstreamとして扱うことができる。
char型のコンテナをバッファとして保持し、string bufferを扱う。

iostreamを継承しているため、バッファへの格納、バッファからの取り出しが行える。


[sample_code](/stream/src/stream_sample.cpp)

