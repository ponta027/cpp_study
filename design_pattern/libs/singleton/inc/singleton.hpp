#ifndef SINLETON_HPP
#define SINLETON_HPP

#include <iostream>
#include <memory>
#include <mutex>

/**
 * @brief
 */
class Singleton
{
public:
  static Singleton &GetInstance()
  {
    static std::unique_ptr<Singleton> instance;
    static std::once_flag flag;
    std::call_once(flag, []() { instance.reset(new Singleton); });
    return *instance;
  }
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  ~Singleton()
  {
    std::cout << "delete instance" << std::endl;
  }

protected:
  Singleton()
  {
    std::cout << "create instance" << std::endl;
  }
};
#endif
