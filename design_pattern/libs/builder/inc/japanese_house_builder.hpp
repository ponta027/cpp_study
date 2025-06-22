#ifndef JAPANESE_HOUSE_BUILDER_HPP_
#define JAPANESE_HOUSE_BUILDER_HPP_

#include "builder.hpp"

class JapaneseHouseBuilder : public IBuilder
{
private:
  IBuilding *building_;

public:
  JapaneseHouseBuilder(){
    building_ = new Building();
  }
  void BuildBase() override;
  void BuildFrame() override;
  void BuildWall() override;
  IBuilding *GetResult() override;
};

#endif
