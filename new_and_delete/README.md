## new と delete

※メモリ領域に関する説明はここでは行わない。（スタック、ヒープ、テキスト、const領域など）

[new 演算子](https://ja.wikipedia.org/wiki/New%E6%BC%94%E7%AE%97%E5%AD%90)

* インスタンスを作成する演算子
    * ヒープ領域からの動的メモリ確保（動的記憶域確保）を伴う。
* newはメモリ確保に対して、delete 演算子でメモリ領域の解放を行う。
    * newしたものはdeleteしないとメモリリークが発生するので注意する。

クラスのメモリ確保/解放はmalloc/freeでも実現できるが、コンストラクタ、デストラクタの処理が行われない。
クラス内のポインタ変数などの領域確保/解放などをする際は別途確保/解放の呼び出しを行う必要がある。
手間を考えるとnew /deleteを使うのが適切。


インスタンスの定義方法としては２種類になる。

* スタック領域
* ヒープ領域

```cpp
class Person{
   public:
    std::string name;
    int age;
    Person(std::string _name, int _age);
}

Person::Person(std::string _name, int _age):name(_name),age(_age)
{

}

{
    Person p = Person("test",10);
    Person* p1 = new Person("test",10);
}    // pオブジェクトはスタック領域に確保されているため、ここで解放処理(デストラクタの呼び出し)が実行される。
     // p1オブジェクトはヒープ領域に確保されているため、解放処理(デストラクタの呼び出し)は実行されない。
```

ヒープ領域に確保したオブジェクトを解放するためにはdelete 演算子で解放処理を明示的に呼び出す必要がある。
解放処理を明示的に呼び出さないとメモリが残り続けてしまい、メモリリークを起こす。

基本的、オブジェクトの利用区間が変数宣言したスコープ内か、スコープ外かで使い分けるのが一般的である。
※実装方法の一例のため、必ずしもそうなるとは限らない。
　スコープ外でもクラスのコピーなどで代用できることもある。

スコープ内であれば、スタック領域に確保したほうが、new,deleteの処理が必要ないため、簡単に実装できる。

※C++11などではunique_ptrが導入され、解放忘れ対策が取られている実装となっている。




* 組み込み変数に関するメモリ確保

```cpp

#include <iostream>
using namespace std;

#define SIZE 255

int main(){

  int *p1;
  int *p2;

  p1 = new int;         // (※) int 型変数１個のメモリ確保

  p2 = new int[SIZE];   // (※) int 型の配列 (要素数 SIZE) のメモリ確保

  *p1 = 1000;

  cout << "p1 が指している整数型は: " << *p1 << "\n";

  // p2 の利用部は各自で例を考えて書いてみること

  delete p1;    // (※) メモリの解放
  delete[] p2;  // (※) メモリの解放 (１要素と配列とで異なる！！)

  return 0;
}
```


* クラスのメモリ確保の例

```cpp
#include <iostream>
using namespace std;

class samp{

    int i, j;

  public:

    samp(){    // デフォルトコンストラクタ
       cout << "default constructor\n"; 
    }

    samp(int a, int b){    // 引数つきコンストラクタ
       i = a; 
       j = b; 
       cout << "constructor with arguments\n";
    }

    ~samp(){ cout << "destructor\n";}  // デストラクタ

    void set_ij(int a, int b){ i=a; j=b;}
    int get_product(){ return i*j; }

};

int main(){

  samp *p1;
  samp *p2;
  samp *p3;

  p1 = new samp;      // オブジェクト１個   (引数なし)
  p2 = new samp(6,5); // オブジェクト１個   (引数あり)
  p3 = new samp[10];  // オブジェクト１０個の配列 (引数なし)

  p1->set_ij(4,5);

  for(int i=0 ; i<10 ; i++){
    p3[i].set_ij(i,i);
  }

  cout << "p1 の積は: " << p1->get_product() << "\n";
  cout << "p2 の積は: " << p2->get_product() << "\n";
  for(int i=0 ; i<10 ; i++)
    cout << "p3[" << i << "]の積は: " << p3[i].get_product() << "\n";

  delete p1;
  delete p2;
  delete[] p3;

  return 0;
}
```
