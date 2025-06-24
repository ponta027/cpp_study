#ifndef PRODUCT_ADAPTER_H
#define PRODUCT_ADAPTER_H

#include "product.h"
#include "product_price.h"

class ProductAdapter : public ProductPrice
{
private:
  Product *product;

public:
  int GetPrice() override;
};
#endif
