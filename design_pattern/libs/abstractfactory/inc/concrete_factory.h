#ifndef CONCRETE_FACTORY_H_
#define CONCRETE_FACTORY_H_

#include "abstract_factory.h"
#include "product_a.h"
#include "product_b.h"
#include <iostream>

class ConcreteFactory : public AbstractFactory
{
public:
  ProductA *createProductA() override;
  ProductB *createProductB() override;
  ~ConcreteFactory()
  {
    std::cout << "delete ConcreteFactory" << std::endl;
  };
};
#endif
