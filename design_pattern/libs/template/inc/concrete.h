#ifndef CONCRETE_H_
#define CONCRETE_H_

#include "abstract.h"

class Concrete : public Abstract{
  public: 
  std::string pre_process() override;
  std::string post_process() override;
 
};

#endif
