#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include "builder.hpp"
#include "building.hpp"

class IDirector
{
public:
  virtual IBuilding* Construct() = 0;
};

class Director : public IDirector
{
private:
  IBuilder *builder_;

public:
  Director(IBuilder *builder) : builder_(builder){};
  IBuilding* Construct() override
  {
    builder_->BuildBase();
    builder_->BuildFrame();
    builder_->BuildWall();
    return builder_->GetResult();
  };
};
#endif
