#ifndef BUILDER_HPP_H
#define BUILDER_HPP_H


#include "building.hpp"
class IBuilder
{
private:
public:
  virtual void BuildBase() = 0;
  virtual void BuildFrame() = 0;
  virtual void BuildWall() = 0;
  virtual IBuilding* GetResult() = 0;
};

#endif /* BUILDER_HPP_H */
