#include "building.hpp"
#include <string>
std::string MaterialtoString(const Material m) {
    switch (m) {
        case Material::WOOD:     return "WOOD";
        case Material::CLAY:     return "CLAY";
        case Material::CONCRETE: return "CONCRETE";
        case Material::SNOW:     return "SNOW";
        default: return "UNKNOWN";
    }
}


void Building::setBase(Material m)
{
  base = m;
}
void Building::setFrame(Material m)
{
  frame = m;
}
void Building::setWall(Material m)
{
  wall = m;
}

std::string Building::toString(void) const
{
  std::string b = MaterialtoString(base);
  return "Base:"+b+",Frame:"+MaterialtoString(frame)+",Wall:"+MaterialtoString(wall);//+ toString(base) + ",Frame:"+toString(frame)+",Wall:"+toString(wall);
}


