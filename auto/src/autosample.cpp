#include <iostream>
#include <typeinfo

int main(int argc, char** argv) {
  auto i = 0;
  const auto j = 0L;
  auto& r = i;
  auto pair = std::make_pair("a", 1);
  auto s = "";

  std::cout << i << std::endl;
  std::cout << j << std::endl;
  std::cout << r << std::endl;
  std::cout << pair.first << pair.second << std::endl;
  std::cout << s << std::endl;
  return 0;
}
