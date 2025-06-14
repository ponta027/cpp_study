#ifndef FCTORY_A_H_
#define FCTORY_A_H_

#include "factory.h"

class FactoryA : public Factory {
  public:
    Product* createProduct() override;
    ~FactoryA() override;
};
#endif
