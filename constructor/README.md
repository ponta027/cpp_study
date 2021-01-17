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
