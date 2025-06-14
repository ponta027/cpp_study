#include "../inc/factory_a.h"
#include "../inc/product_a.h"

Product* FactoryA::createProduct()
{
  return static_cast<Product*>(new ProductA());
}
FactoryA::~FactoryA(){}
