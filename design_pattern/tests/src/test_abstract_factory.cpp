#include "abstract_factory.h"
#include "concrete_factory.h"
#include "product_a.h"
#include "product_b.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>

TEST(AbstractFactoryTest, BasicAssert)
{

  std::unique_ptr<AbstractFactory> factory = std::make_unique<ConcreteFactory>(); // OK
  ProductA* a= factory->createProductA();
  ProductB* b= factory->createProductB();

  ASSERT_EQ(20, 20);
}
