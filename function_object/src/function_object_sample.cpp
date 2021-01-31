#include <iostream>

struct doubler {
  int operator()(int x) const { return x * 2; }
};

int main(int argc, char* argv[]) {
  auto x = 10;
  doubler d;
  std::cout << d(x) << std::endl;

  return 0;
}
