#include "builder.hpp"
#include "director.hpp"
#include "japanese_house_builder.hpp"

#include <gtest/gtest.h>
#include <iostream>

TEST(BuilderPattern, BasicAssert)
{

  IBuilder *builder = new JapaneseHouseBuilder();
  IDirector *director = new Director(new JapaneseHouseBuilder());
  IBuilding *building = director->Construct();

  std::cout << *building << std::endl;
  ASSERT_EQ(building->toString(), "Base:CONCRETE,Frame:WOOD,Wall:CLAY");
}

