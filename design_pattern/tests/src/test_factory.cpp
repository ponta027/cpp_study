#include "factory_a.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(Factory, BasicAssert)
{

  FactoryA fact;
  Product *product = fact.createProduct();
  ASSERT_EQ(10, product->getData());
}
