#ifndef BUILDING_HPP_H
#define BUILDING_HPP_H

#include <iostream>
#include <ostream>

enum class Material : uint32_t
{
  WOOD,
  CLAY,
  CONCRETE,
  SNOW
};

std::string MaterialtoString(const Material m) ;
class IBuilding
{
public:
  IBuilding(){};
  virtual void setBase(Material m) = 0;
  virtual void setFrame(Material m) = 0;
  virtual void setWall(Material m) = 0;
  virtual std::string toString(void) const = 0;
  friend std::ostream &operator<<(std::ostream &os, const IBuilding &obj)
  {
    os << "Base:" << obj.toString();
    return os;
  }
};

class Building : public IBuilding
{
  Material base;
  Material frame;
  Material wall;

public:
  Building()
  {
    std::cout << "create Instance" << std::endl;
  }

  void setBase(Material m) override;
  void setFrame(Material m) override;
  void setWall(Material m) override;
  std::string toString(void) const override;
};

#endif
