#ifndef PRODUCT_B_H_
#define PRODUCT_B_H_
#include "product.h"

class ProductB : public Product
{
public:
  void use() override;
  int getData() override;
  ~ProductB() override;
};
#endif
