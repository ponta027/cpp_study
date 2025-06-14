#include "singleton.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(Singleton, BasicAssert)
{

  // change stdout to buf
  std::streambuf *originalCout = std::cout.rdbuf();
  std::ostringstream buffer;
  std::cout.rdbuf(buffer.rdbuf());

  Singleton &instance = Singleton::GetInstance();

  std::string output = buffer.str();
  std::cout.rdbuf(originalCout);

  EXPECT_STRNE("hello", "world");
  ASSERT_EQ(output, "create instance\n");
}
