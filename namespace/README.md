## namespace

[名前空間](https://ja.wikipedia.org/wiki/%E5%90%8D%E5%89%8D%E7%A9%BA%E9%96%93)

> 名前空間（なまえくうかん）はNamespaceの訳語で、名前の集合を分割することで衝突の可能性を低減しつつ参照を容易にする概念である。
この集合は、全事象の元の全ての組み合わせ可能なものからなる集合全体および物理的な名称を指すことが可能である。つまり英字・数字・記号などを組みあわせて作られる名前全てを含む集合である。名前に結び付けられる実体（型や変数）は、名前がそれぞれどの集合（空間）に属するか指定されることで一意に定まる。名前空間が異なれば同じ名前でも別の実体に対応付けられる。


```eval_rst

.. uml::

    package namespace:A
    {
    class Person
    }

    package namespace:B
    {
    class Person　
    }

```


同じ名前でもnamespaceが異なれば名前の衝突が発生しない。
大規模開発になると、同じクラス名やメソッド名などを定義したいケースが出てくる。
その時にnamespaceの概念を導入することにより、衝突を解消することができる。

クラス名などにnamespace名をつける事により衝突を回避することができるかもしれない。
命名についてはなるべくシンプルかつ短い名称をつけるほうがよいため、上記のような方法は取らない。


### namespaceの定義と使用方法

#### クラス定義
namespaceを定義し、そのnamespace内にクラスなどを定義したい場合には、以下のように実装する。

```c
namespace sample{
  class Person{
     public:
     std::string name;
     int age;
     void sayHello();
  }
}
```

* クラスの実装

```c
sample::Person::Person(){
}
```

* using namespaceを使うとそのファイル内ではnamespaceを省略することができる。

```c
using namespace sample
Person::Person(){
}
```

実際にクラスを呼び出す場合

```c
{
    sample::Person test;
}
```

```c
using namespace sample;
{
    Person test;
}
```


注意点：using namespaceを使いすぎると衝突回避に導入されたはずだが、衝突してしまう可能性がある。そのため、使いすぎに注意。

上述のクラス図の両方を同一ファイル内で呼び出す場合、
A,Bのnamespaceに対して、using namespaceを宣言すると。

```c
using namespace A;
using namespace B;

{
     Person test; // A::Person なのか、B::Personなのか区別がつかなくなってしまう。
}
```


#### メソッド定義

namespace直下にメソッド、変数を定義することは可能。

```c
namespace sample{
   void helloWorld(){ std::cout << "Hello World"<< std::endl;}
}

{
    sample::helloWorld();  // namespaceを付与して呼び出す。
}
```

また、namespaceのネストを定義することが可能


#### namespaceのネスト

```eval_rst
.. uml::

    package namespace:A
    {
         package namespace:B{
              class Person
         }
    }

    package namespace:B　
    {
         package namespace:C{
              class Person　
         }
    }

```

同階層でなければ、同じnamespace名もOK
フォルダと同じ考え方をすれば良い。
