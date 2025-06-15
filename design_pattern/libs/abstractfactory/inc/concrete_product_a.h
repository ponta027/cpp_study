#ifndef CONCRETE_PRODUCT_A_H_
#define CONCRETE_PRODUCT_A_H_
#include "product_a.h"
#include <iostream>
class ConcreteProductA : public ProductA
{
public:
  void paint() override
  {
    std::cout << "Concreted ProductA"<< std::endl;
  }
};
#endif
