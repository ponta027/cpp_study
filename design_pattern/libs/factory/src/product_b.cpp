#include "../inc/product_b.h"
#include <iostream>


void  ProductB::use(){
  std::cout << "Product B" << std::endl;
}
int ProductB::getData()
{
  return 20;
}
ProductB::~ProductB(){}
