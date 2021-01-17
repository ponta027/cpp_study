## 関数の引数について

関数の引数の定義には3種類存在する。

* 値渡し
* ポインタ渡し
* 参照渡し

### 値渡し

関数に渡すときに値がコピーされる。

```c

void func( int a ){
    a = 10;
    std::cout << a << std::endl;//10が出力     
    return;
}
int main(int argc,char** argv){
    int a=0;
    func(a);
    std::cout << a << std::endl;//0が出力
    return 0;
}
```

関数呼び出しの時に値のコピー処理が行われるため、原則として値渡しで構造体を渡さない。
理由としては、引数を構造体にしておくと、構造体のメンバーを追加した場合に、
コピー処理の時間が増えてしまい、関数のオーバーヘッドが増えてしまう。

### ポインタ渡し


関数に渡すときにアドレスがコピーされる。


```c

void func( int* a ){
    *a = 10;
    std::cout << a << std::endl;//10が出力     
    return;
}
int main(int argc,char** argv){
    int a=0;
    func(&a);
    std::cout << a << std::endl;//10が出力
    return 0;
}
```

関数の呼び元でaのアドレスを渡す。
関数の仮引数にアドレスが設定される。
仮引数に格納されているアドレスを使って、値の参照及び変更を行う。

### 参照渡し

別名エイリアスとも呼ばれる。
C++特有の記述方法。


```c

void func( int& a ){
    a = 10;
    std::cout << a << std::endl;//10が出力     
    return;
}
int main(int argc,char** argv){
    int a=0;
    func(a);
    std::cout << a << std::endl;//10が出力
    return 0;
}
```

関数の呼び元で変数を渡す。
関数の仮引数ではaはアドレス経由(間接参照演算子）ではなく直接参照及び変更を行う。

実はアセンブラレベルになるとポインタ渡しと変わりないらしい。

#### 参照渡しとポインタ渡しの違い。

参照渡しは関数内部ではnullptrではないことを保証する設計となる。
実際nullptrを渡したらNullPointerExceptionが発生します。

参照渡し、ポインタ渡しをどちらを使ったほうが良いか？

組み込み型はポインタ渡しを使ったほうが、可読性が上がる。
ポインタ渡し＝変更される前提で渡す。
組み込み型以外は参照渡しのほうがよいかと思います。

### constについて

const関数を定義することができる。


```c

class Color
{
private:
    UInt08 r, g, b;

public:
    Color() {}

    Color(UInt08 r0, UInt08 g0, UInt08 b0)
    {
        r = r0;
        g = g0;
        b = b0;
    }

    UInt08 GetRed()   const { return r; }
    UInt08 GetGreen() const { return g; }
    UInt08 GetBlue()  const { return b; }

    Void SetRed(UInt08 n)   { r = n; }
    Void SetGreen(UInt08 n) { g = n; }
    Void SetBlue(UInt08 n)  { b = n; }
};
```

この場合、関数内でオブジェクトの変更ができないことを定義することができる。
オブジェクトの状態が変更しないことを保証する関数であることを明示している。

#### 関数の引数のconst

* 型の前にconstを付けた場合、値が変更不可
* 型の後ろにconstを付けた場合、アドレスの変更が不可

```c

void func(const char* tmp )   // 値の変更不可
{
    return;
}
void func(char* const tmp )   // アドレスの変更不可: tmp++みたいなことができない。
{
    return;
}

int main(int argc,char** argv){
    char* tmp = "test";
    func(tmp); 
}
```
