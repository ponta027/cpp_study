#ifndef PRODUCT_A_H_
#define PRODUCT_A_H_
#include "product.h"

class ProductA : public Product
{
public:
  void use() override;
  int getData() override;
  ~ProductA() override;
};
#endif
