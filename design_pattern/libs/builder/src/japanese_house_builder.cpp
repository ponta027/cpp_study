#include "japanese_house_builder.hpp"
#include "building.hpp"

void JapaneseHouseBuilder::BuildBase()
{
  building_->setBase(Material::CONCRETE);
}
void JapaneseHouseBuilder::BuildFrame()
{
  building_->setFrame(Material::WOOD);
}
void JapaneseHouseBuilder::BuildWall()
{
  building_->setWall(Material::CLAY);
}
IBuilding *JapaneseHouseBuilder::GetResult()
{

  return building_;
}

