#include "abstract.h"
#include "concrete.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>

class MockTemplate : public Abstract
{
public:
  MOCK_METHOD(std::string, pre_process, (), (override));
  MOCK_METHOD(std::string, post_process, (), (override));
};

using ::testing::Return;

TEST(Template, BasicAssert)
{
  std::shared_ptr<Abstract> ptr = std::make_shared<MockTemplate>();
  auto &foo = dynamic_cast<MockTemplate &>(*ptr);
  ON_CALL(foo, pre_process()).WillByDefault(Return("/*"));
  ON_CALL(foo, post_process()).WillByDefault(Return("*/"));

  EXPECT_CALL(foo, pre_process()).Times(1).WillRepeatedly(Return("/*"));
  EXPECT_CALL(foo, post_process()).Times(1).WillRepeatedly(Return("*/"));
  auto ret = ptr->display("HOGE");
  ASSERT_EQ("/*HOGE*/", ret);
}
