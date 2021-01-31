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

以上
