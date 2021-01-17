
https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%A9%E3%82%B9_(%E3%82%B3%E3%83%B3%E3%83%94%E3%83%A5%E3%83%BC%E3%82%BF)

> オブジェクト指向プログラミングにおけるクラス（英: class）[1]とは、オブジェクトを生成するための設計図あるいはひな形に相当するものである。抽象データ型の一つ。クラスから生成したオブジェクトの実体のことをインスタンスという。

クラスは型、インスタンスは型から生成された実体


クラスを構造体に置き換えて解釈すると、構造体定義がクラス、構造体の変数がインスタンス

### 構造体の実装

```cpp
struct Person{
   std::string name;
   int         age;
}


Person test;
test.name = "shibuya";
test.age = 40;
// C言語だとtypedefする必要があるが、C++の構造体は不要。

```

### クラスの実装

```cpp
class Person{
   pulic:
   std::string name;
   int         age;
}

Person test;
test.name = "shibuya";
test.age = 40;
```

クラスに定義された変数を「メンバー変数」と呼ぶ。
クラスと構造体の違い：publicがついているかついていないか。
publicなどの説明については後述。

### メソッド

クラスには構造体とは異なりクラス内にメソッド（関数）を定義することができる。

```cpp
class Person{
   pulic:
   std::string name;
   int         age;
   void sayHello();
}

void Person::sayHello(){
   std::cout << "Hello World "<< name << std::endl;
   return 0;
}

Person test;
test.name = "shibuya";
test.age = 40;
test.sayHello():

```

クラス内にメソッドのみ定義して、メソッドの実体を実装する。
**クラス名::メソッド名** という形式で実装する。

また、クラス内のメソッドの定義および実装を含めるケースも存在する。


```cpp
class Person{
   pulic:
   std::string name;
   int         age;
   void sayHello(){
   std::cout << "Hello World "<< name << std::endl;
   return 0;
   }
}



Person test;
test.name = "shibuya";
test.age = 40;
test.sayHello():

```

基本的に前者の実装のほうがよい。
ヘッダファイルとソースコードの分離した時に効果的になる。

### アクセス修飾子

クラスではアクセス修飾子が存在する。

* public
    * クラス外部からアクセス可能
* private
    * クラス内部からのみアクセス可能
* protected
    * 継承したクラスでのみアクセス可能

protectedの説明については、継承の時に説明します。


実装例:メソッドをprivateにしてみた。

```cpp
class Person{
   pulic:
   std::string name;
   int         age;
   private:
   void sayHello(){
   std::cout << "Hello World "<< name << std::endl;
   return 0;
   }
}



Person test;
test.name = "shibuya";
test.age = 40;
test.sayHello()://  <-----privateは外部からアクセスできないというコンパイルエラーが発生

```


```cpp
class Person{
   pulic:
   std::string name;
   int         age;
   void sayHello(){
       std::cout << "Hello World "<< name << std::endl;
       test();
       return 0;
   }
   private:
   void test(){std::cout << "test"<< std::endl;}    //自分のクラスのメソッドからしか呼び出されない場合privateにする。
}



Person test;
test.name = "shibuya";
test.age = 40;
test.sayHello():
// 下記が出力される。
// HelloWorld shibuya
// test 
```
