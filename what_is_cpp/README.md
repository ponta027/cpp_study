## C++とは

https://ja.wikipedia.org/wiki/C%2B%2B

> C言語の機能や特徴を継承しつつ、表現力と効率性の向上のために、手続き型プログラミング・データ抽象・オブジェクト指向プログラミング・ジェネリックプログラミングといった複数のプログラミングパラダイムが組み合わされている
C言語のようにハードウェアを直接扱うような下位層向けの低水準言語としても、複雑なアプリケーションソフトウェアを開発するための上位層向け高水準言語としても使用可能である。

```cpp
#include <iostream>
void hello_World( void ){
    std::cout << "Hello World << std::endl;
    return;
}
int main(int argc char** argv){
    hello_World();
    return 0;
}
```

WSL上でのコンパイル方法

```cpp
g++ -o sample sample.cpp
./sample
```
