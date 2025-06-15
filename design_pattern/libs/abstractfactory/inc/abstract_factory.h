#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include "product_a.h"
#include "product_b.h"

class AbstractFactory
{
public:
  virtual ProductA *createProductA() = 0;
  virtual ProductB *createProductB() = 0;
};
#endif
