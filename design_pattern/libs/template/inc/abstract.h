#ifndef ABSTRACT_H_
#define ABSTRACT_H_
#include <string>

class Abstract
{
protected:
  virtual std::string pre_process() = 0;
  virtual std::string post_process() = 0;
public:
  std::string display(std::string a)
  {
    std::string pre_str = pre_process();

    std::string post_str = post_process();
    return pre_str + a + post_str;
  };
};
#endif
