#include "singleton.hpp"
#include <iostream>
int main(int argc, char *argv[])
{

  std::cout << "START" << std::endl;
  {
  Singleton::GetInstance();
  }
  std::cout << "END" << std::endl;

  return 0;
}
