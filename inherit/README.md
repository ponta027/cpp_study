## 継承

https://ja.wikipedia.org/wiki/%E7%B6%99%E6%89%BF_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)

> オブジェクト指向を構成する概念の一つである。あるオブジェクトが他のオブジェクトの特性を引き継ぐ場合、両者の間に「継承関係」があると言われる。
主にクラスベースのオブジェクト指向言語で、既存クラスの機能、構造を共有する新たなクラス（派生クラス、派生型）を定義すること（subclassing、サブクラス化）ができる。またそのような派生クラスは「親クラス（スーパークラス）を継承した」という。具体的には変数定義（フィールド）や操作（メソッド）などが引き継がれる。


継承：あるオブジェクトがほかのオブジェクトの特性を引き継ぐ。

```eval_rst
.. uml::


    class Car{
        void drive();
    }
    class PoliceCar extends Car {
        void siren();
    }

```

車の場合

* 車：運転する
* パトカー：運転する+サイレンを鳴らす

車とパトカーは同じ機能を持っている。
つまりパトカーは( 車の機能 + パトカー特化の機能）で実現できる。

### ポリモーフィズム

https://ja.wikipedia.org/wiki/%E3%83%9D%E3%83%AA%E3%83%A2%E3%83%BC%E3%83%95%E3%82%A3%E3%82%BA%E3%83%A0

> プログラミング言語の各要素（定数、変数、式、オブジェクト、関数、メソッドなど）についてそれらが複数の型に属することを許すという性質を指す。ポリモルフィズム、多態性、多相性、多様性とも呼ばれる。

簡単に言うと、同じ名前でも振る舞いが異なる事ができる。

同じ関数名でも異なる引数を定義できる：オーバーロード
同じクラス名でも異なる振る舞いを呼び出す事ができる：継承


* アドホック多相（Ad hoc polymorphism）：ある関数が、異なる型の引数に対してそれぞれ異なる実装を持つ場合。多くのプログラミング言語で関数の多重定義としてサポートされる。  
  → オーバーロード
* パラメータ多相（Parametric polymorphism）：コードが特定の型を指定せずに書かれることで、さまざまな型に対して透過的に使用できる場合。オブジェクト指向言語ではジェネリクスやジェネリックプログラミングとしても知られる。関数型言語の分野ではパラメータ多相のことを指して単に多相性と呼ぶ場合がある。  
　→ジェネリクス(別途説明)
* 部分型付け（Subtyping）：部分型多相（subtype polymorphism）や包含多相（inclusion polymorphism）とも。共通の上位型をもつ複数の型を、1つの名前で扱う場合。オブジェクト指向言語の分野では部分型付けのことを指して単にポリモーフィズムと呼ぶ場合がある。  


#### アドホック多相

```c
#include <iostream>
#include <string>

int Add(int x, int y) {
    return x + y;
}

std::string Add(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

int main() {
    std::cout << Add(1, 2) << std::endl; // "3" が出力される。
    std::cout << Add("Hello, ", "World!") << std::endl; // "Hello, World!" が出力される。
}
```

### 部分型付け


```c
class Animal {
    protected: 
    virtual std::string talk();
}

class Cat : public Animal {
    public:
    std::string talk() override {
        return "Meow!";
    }
}

class Dog : public Animal {
    public:
    std::string talk() override {
        return "Woof!";
    }
}

class Test {
    public:
         void letsHear(const Animal a) {
            std::cout << a.talk() <<std::endl;;
         }
         void main() {
            letsHear(new Cat());
           letsHear(new Dog());
         }
}

```

### 集約/コンポジション

継承と類似の概念に「委譲」があるが、継承では一度定まった継承関係は通常変更されないのに対して、委譲対象は必要に応じて変更されうるものである。
Is-a関係を持つ継承とは階層が異なる概念として集約 (aggregation) とコンポジション集約 (composition) があるが、これはクラス間の関係がHas-aである包含関係であり、クラス間の関係は継承よりも疎である。

```eval_rst
.. uml::

    Sample *-- Sample2

    Class05 o-- Class06

```

```c

is-a:composition

struct Class05
{
   struct Class06{
   };
};

has-a:aggregation

class Sample{
 
   public:
      Sample2* sample=null; 
      void create(){
          sample = new Sample2();
      }
}     
```
