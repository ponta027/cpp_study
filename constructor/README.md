https://ja.wikipedia.org/wiki/%E3%82%B3%E3%83%B3%E3%82%B9%E3%83%88%E3%83%A9%E3%82%AF%E3%82%BF


> コンストラクタ（英: constructor）は、オブジェクト指向のプログラミング言語で新たなオブジェクトを生成する際に呼び出されて内容の初期化などを行なう関数あるいはメソッドのことである。対義語はデストラクタ。
オブジェクトの生成は、
メモリ割当（英: allocation）
初期化（英: initialization）
の二段階を経て行なわれるが、コンストラクタを持つプログラミング言語ではメモリ割り当ては言語機能に組み込まれ、初期化用のコードのみを記述するのが普通である。


　

> デストラクタ（英: destructor）は、オブジェクト指向プログラミング言語でオブジェクトを削除する際に呼び出されて後処理などを行なう関数あるいはメソッドのこと。C++やDelphiにおいてサポートされている。デストラクタは確実かつ安全なリソース管理を実現するための重要な役割を担う。

### コンストラクタ

コンストラクタの識別子はクラス名と同じにする。
コンストラクタを明記しないとデフォルトコンストラクタが呼び出される。
デフォルトコンストラクタは引数なしのコンストラクタ

```cpp
class Person{
   public:
   std::string name;
   int         age;
}


{
     Person test; // ここで呼び出した段階でコンストラクタが呼び出される。
} 
```



```cpp
class Person{
   public:
   std::string name;
   int         age;
   Person();
}

Person::Person()        //コンストラクタを明示的に記述するとことができる。
{
}
```

コンストラクタに引数を渡す場合

```cpp
class Person{
   public:
   std::string name;
   int         age;
   Person(std::string _name,int _age);
}

Person::Person(int _name , int _age):name(_name),age(_age)  // コンストラクタの引数でメンバー変数を初期化することができる。
{
}
```


```cpp
class Person{
   public:
   std::string name;
   int         age;
   Person(std::string _name,int _age);
}

Person::Person(int _name , int _age) // コンストラクタの引数でメンバー変数を初期化することができる。
{
    name = _name;
    age  = _age;
}
```

### デストラクタ

デストラクタは基本的に引数を持たない。
デストラクタを定義する場合には、~クラス名で定義する。
デストラクタもデフォルトのデストラクタが存在する。
コンストラクタでメンバー変数に動的メモリ確保した場合、デストラクタで解放したりします。


```c
class Person{
   public:
   std::string name;
   int         age;
}


{
     Person test; // ここで呼び出した段階でコンストラクタが呼び出される。
}                 // スコープから抜ける時デストラクタが呼び出されはオブジェクトが破棄されます
```

```c
class Person{
   public:
   std::string name;
   int         age;
   Person(std::string _name,int _age);
   ~Person()
}

Person::Person(std::string _name , int _age):name(_name),age(_age)  // コンストラクタの引数でメンバー変数を初期化することができる。
{
}
Person::~Person()
{
    name="";
    age=0;
}

{
     Person test;
}
```


```c
class Person{
   public:
   char* name;
   int         age;
   Person(char* _name,int _age);
   ~Person()
}

Person::Person(char* _name , int _age):age(_age)  // コンストラクタの引数でメンバー変数を初期化することができる。
{
   name = malloc( 10 ) ; // 10文字以上渡ってこない想定とする。
   memcpy( name , _name, 10 );
}
Person::~Person()
{
    free( name );
    age=0;

}

{
     Person test;
}
```





## コンストラクタ2

クラスには初期化を行うためのコンストラクタ、終了処理のためのデストラクタが存在する。
またクラスを定義した場合、以下のコンストラクタ/デストラクタがデフォルトで作成される。

* デフォルトコンストラクタ
    * 既出のため説明対象外
* コピーコンストラクタ
     * オブジェクトのコピーが行われるときに呼び出されるコンストラクタ
         * オブジェクトの初期化
         * 関数へのオブジェクトの値渡し
         * 関数の戻り値をオブジェクトで戻り値を変数宣言し代入する
* コピー代入演算子
    * 代入演算子をコピー
* ムーブコンストラクタ
    * オブジェクトの内部値を新たなオブジェクトに移動／譲渡するための特殊なコンストラクタ(別途説明)
* ムーブ代入演算子
    * オブジェクトの所有権を奪う代入演算子(別途説明)
* デストラクタ
    * 既出のため説明対象外

### 引数ありコンストラクタ

```cpp

class Person
{
    private:
      std::string name;
      int         age;
    public:
      Person( std::string _name, int _age);
}

Person::Person(std::string _name , int _age):name(_name),age(_age)
{
}
```

### コピーコンストラクタ

```cpp
#include <iostream>
#include <string>
class Person{
	private:
		std::string name;
		int age;
	public:
		Person( std::string _name, int _age);
		Person(const Person &o);
		std::string getName(void){return name;}
		Person& operator=(const Person&);

};

Person::Person(std::string _name,  int _age): name(_name),age(_age){
	std::cout << "Call Default Constructor"<< std::endl;
}
Person::Person(const Person & o ):name(o.name),age(o.age){
	std::cout << "Call Copy Constructor"<< std::endl;
}
Person& Person::operator=(const Person& o ){
	std::cout << "Call Copy Operator"<< std::endl;
	name = o.name;
}

int main(int argc,char** argv){
	Person person("test",10);//デフォルトコンストラクタ

	std::cout << person.getName() << std::endl;
	Person person2 = person;//コピーコンストラクタ
	std::cout << person2.getName() << std::endl;

	Person personz("z",10);
	personz = person2;//    コピー代入演算子

	std::cout << personz.getName() << std::endl;
	return 0;
}

```

### default , delete 

= defaultは、「暗黙定義されるデフォルトの挙動を使用し、inlineやvirtualといった修飾のみを明示的に指定する」という目的に使用する機能である：

= deleteは、特殊関数の暗黙定義を明示的に禁止するための機能である。これは、コピーを禁止するクラスを定義するような場合に使用する：

```cpp
class X {
public:
  // コピーは禁止するが、ムーブは許可する
  X(const X&) = delete;
  X& operator=(const X&) = delete;

  // 特殊メンバ関数を明示的に定義もしくはdeleteした場合、
  // それ以外の特殊メンバ関数は明示的に定義もしくはdefault宣言しなければ
  // 暗黙定義されない
  X(X&&) = default;
  X() = default;
  X& operator=(X&&) = default;
};

int main()
{
  X x1;
//X x2 = x1;  // コンパイルエラー！Xのコピーコンストラクタはdelete宣言されている
  X x3 = X(); // OK : ムーブコンストラクトはできる

  X x4;
//x4 = x1;    // コンパイルエラー！Xのコピー代入演算子はdelete宣言されている

  X x5;
  x5 = X();   // OK : ムーブ代入はできる
}
```
