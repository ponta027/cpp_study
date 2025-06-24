#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product
{
private:
  int cost_ = 0;

public:
  Product(int cost) : cost_(cost){};
  int GetCost()
  {
    return cost_;
  }
};
#endif
