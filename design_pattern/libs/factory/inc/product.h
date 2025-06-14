#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product
{
public:
  virtual void use() = 0;
  virtual int getData() = 0;
  virtual ~Product() {};
};
#endif
