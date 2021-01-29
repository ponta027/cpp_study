#include <iostream>
#include <vector>

class UniformInitializer {
 public:
  UniformInitializer(int x, double y, std::string name);
  int x;
  double y;
  std::string name;


};
UniformInitializer::UniformInitializer(int x, double y, std::string name) {
  this->x = x;
  this->y = y;
  this->name = name;
}

std::ostream& operator<<(std::ostream& os,
			       const UniformInitializer& initializer) {
  os << "{";
  os << initializer.x;
  os << ",";
  os << initializer.y;
  os << ",";
  os << initializer.name;
  os << "}";
  return os;
}
template <typename T>
class InitializerSample {
 private:
  std::vector<T> data_;

 public:
  InitializerSample(std::initializer_list<T> init);
};

template <typename T>
InitializerSample<T>::InitializerSample(std::initializer_list<T> init)
    : data_(init.begin(), init.end()) {}

template <typename T>
class InitializerSample2 {
 private:
  std::vector<T> data_;

 public:
  /**
   * forbid assign operator
   */
  explicit InitializerSample2(std::initializer_list<T> init);
};
template <typename T>
InitializerSample2<T>::InitializerSample2(std::initializer_list<T> init)
    : data_(init.begin(), init.end()) {}

int main(int argc, char* argv[]) {  //

  UniformInitializer x{1, 0.1, "hoge"};

  std::cout << x << std::endl;

  InitializerSample<int> v = {1, 2, 3};
  // InitializerSample2<int> v2 = {1, 2, 3};
  InitializerSample2<int> v2{1, 2, 3};

  return 0;
}
