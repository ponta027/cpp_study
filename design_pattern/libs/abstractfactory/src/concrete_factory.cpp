#include "../inc/concrete_factory.h"
#include "../inc/product_a.h"
#include "../inc/concrete_product_a.h"
#include "../inc/concrete_product_b.h"
#include "../inc/product_b.h"
#include <memory>


ProductA *ConcreteFactory::createProductA()
{
  return static_cast<ProductA*>(new ConcreteProductA());
};
ProductB *ConcreteFactory::createProductB()
{
  return static_cast<ProductB*>(new ConcreteProductB());
};
