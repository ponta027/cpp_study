#include "../inc/product_a.h"
#include <iostream>

void ProductA::use()
{
  std::cout << "use" << std::endl;
  return;
}

int ProductA::getData()
{
  return 10;
}

ProductA::~ProductA(){}
