#include <iostream>

class LambdaSample {
 public:
  LambdaSample(int a);
  int data;
};
LambdaSample::LambdaSample(int a) : data(a) {
  std::cout << "==========================" << std::endl;
  //[this]	*thisのメンバを参照して、ラムダ式のなかで使用する
  auto i = [this] { return this->data; };
  std::cout << i() << std::endl;

  int x = 0xFF;
  //[this, x]
  //*thisのメンバを参照し、変数xのみコピーして、ラムダ式のなかで使用する
  auto j = [this, x] { return this->data + x; };
  std::cout << j() << std::endl;

  std::cout << "==========================" << std::endl;
}
void lambda_test1() {
  auto plus = [](int a, int b) { return a + b; };
  int ret = plus(2, 3);
  auto multi = [](int a, int b) { return a * b; };
  ret = multi(2, 4);

  //
  int data = 10;
  auto increment = [](int* a) {
    *a = *a + 1;
    return;
  };
  increment(&data);
  std::cout << data << std::endl;
}

void lambda_capture() {
  int x = 3;
  // [&]	デフォルトで環境にある変数を参照して、ラムダ式のなかで使用する
  auto f = [&] { x = 1; };
  f();
  std::cout << x << std::endl;

  // [=]	デフォルトで環境にある変数をコピーして、ラムダ式のなかで使用する
  auto g = [=] { return x; };
  std::cout << g() << std::endl;

  // [&y]	変数yを参照して、ラムダ式のなかで使用する
  int y = 10;
  auto h = [&y] {
    y = 5;
    return;
  };

  h();
  std::cout << y << std::endl;

  //[x]	変数xをコピーして、ラムダ式のなかで使用する
  // コピーのため、constになり
  // 代入は不可能。
  auto i = [x] { return x + 10; };
  std::cout << i() << std::endl;

  //[&, x]
  //デフォルトで参照キャプチャ、変数xのみコピーして、ラムダ式のなかで使用する
  auto j = [&, x] {
    y = 0xFF;
    return x + 10;
  };
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << j() << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;

  //[=, &x]
  //デフォルトでコピーキャプチャ、変数xのみ参照して、ラムダ式のなかで使用する
  auto k = [=, &x] {
    x = 0xFF;
    return y + 10;
  };
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << k() << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;

  LambdaSample sample(10);

  return;
}
int main(int argc, char* argv[]) {
  lambda_test1();
  lambda_capture();
  return 0;
}
