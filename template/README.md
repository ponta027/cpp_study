# template


## function template

[sample_code](src/template.cpp)

* add関数をテンプレートで実装
   * operator+ が実装されていればどんな型でも関数を使用することが可能。
   * 使用する型分のオブジェクトが生成される。


```
$ nm --demangle template_sample  | grep add

00010fd8 W Sample add<Sample>(Sample, Sample)
00010fa8 W float add<float>(float, float)!m:
00010f40 W int add<int>(int, int)
00010f70 W std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > add<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
```




## クラステンプレート

[sample_code](src/class_template.cpp)

* Stackクラスをtemplateで実装。
    * 基本的にインスタンスを格納するので、どんなクラスでも対応する実装が可能。

```
$ nm  --demangle class_template.o | grep Stack
00000000 W Stack<some<int, long> >::pop()
00000000 W Stack<some<int, long> >::push(some<int, long>)
00000000 W Stack<some<int, long> >::Stack(int)
00000000 W Stack<some<int, long> >::Stack(int)
00000000 n Stack<some<int, long> >::Stack(int)
00000000 W Stack<some<int, long> >::~Stack()
00000000 W Stack<some<int, long> >::~Stack()
00000000 n Stack<some<int, long> >::~Stack()
00000000 W Stack<int>::pop()
00000000 W Stack<int>::push(int)
00000000 W Stack<int>::Stack(int)
00000000 W Stack<int>::Stack(int)
00000000 n Stack<int>::Stack(int)
00000000 W Stack<int>::~Stack()
00000000 W Stack<int>::~Stack()
00000000 n Stack<int>::~Stack()
00000000 W Stack<some<int, long> >::top() const
00000000 W Stack<int>::top() const
```



## ヘッダとソースコードの分離

* [ヘッダ](inc/template_separate.h)
* [ソース](src/template_separate.cpp)



* クラスの実体を実装する際に関数の１つ１つにtemplateを記述する必要がある。
* クラス/関数テンプレートの実装は通常ヘッダファイルに置き、コンパイル単位内にその実装が現れなければならない  
  インスタンス化のときにはその定義（実装)が必要になるため。
  
nmの結果を見たとおり、コンパイル時に使用する型の実体を作る必要があるため、テンプレートの実装もコンパイル時に知る必要がある。

