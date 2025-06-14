#ifndef FACTORY
#define FACTORY

#include "product.h"

class Factory
{
public:
  virtual Product *createProduct() = 0;
  virtual ~Factory()
  {
  }
};
#endif
