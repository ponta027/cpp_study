# lambda 式

サンプル

```cpp
int main( int argc,char** argv)
{
auto plus = [](int a, int b) { return a + b; };
int result = plus(2, 3); // result == 5
return 0;
}
```

簡易的な関数オブジェクトをその場で定義できる機能。関数オブジェクトを一時的に作り名前をつけなくて良いため、[無名関数](https://ja.wikipedia.org/wiki/%E7%84%A1%E5%90%8D%E9%96%A2%E6%95%B0)と呼ぶ。

無名関数を定義した場合、コンパイラが一時的にオブジェクトを生成する。
caller側で一時的なオブジェクトが渡される様になる。

上述のサンプルコードでは以下のようなコードが自動生成される。
```cpp
struct F {
  auto operator()(int a, int b) const -> decltype(a + b)
  {
     return a + b;
  }
};
```


サンプルプログラムのオブジェクトをダンプして確認する。



```cpp
#include <iostream>

int main(int argc, char* argv[]) {
  auto plus = [](int a , int b ) {return a+b;};
  int ret = plus(2,3);
  return 0;
}
```

```
> nm --demangle lambda_sample
         U abort@@GLIBC_2.4
......................
000105f4 T main
00010528 t register_tm_clones
00010498 T _start
00021030 D __TMC_END__
00010630 t __static_initialization_and_destruction_0(int, int)
         U std::ios_base::Init::Init()@@GLIBCXX_3.4
         U std::ios_base::Init::~Init()@@GLIBCXX_3.4
00010720 r std::piecewise_construct
00021034 b std::__ioinit
000105c0 t main::{lambda(int, int)#1}::operator()(int, int) const
```


最後の行にmain::lambdaというオブジェクトが生成されている。

これがlambda式を実装した際に生成されたオブジェクトである。
同じ関数内にlambda式を複数実装した場合、#1,#2という識別子をつけて生成する。


## キャプチャ機能

lamda式から外側の変数を使用する場合には、「キャプチャ」という機能を使用する。

lambda式の先頭にある[] の中身を指定することにより、どの変数をどのようにキャプチャするかを指定できる。

```cpp

function a()
{
    int x = 3;
    auto f =[&]() { return x  + 1 ;}
}
```
[sample](/lambda/src/lambda_sample.cpp)

以上

