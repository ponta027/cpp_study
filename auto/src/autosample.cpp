#include <iostream>
#include <memory>

void log_debug( std::string s )
{
  std::cout << "[DEBUG]" << s << std::endl;
}
namespace sample {
auto v = {
    1, 7, 3, 2, 0, 5, 0, 8,
};
};

int sampleFunction() {
  auto i = 0;
  return i;
}

std::unique_ptr<int> create_unique_ptr(int i) {
  return std::unique_ptr<int>(i != 0 ? new auto(i) : nullptr);
}

int main(int argc, char** argv) {

  log_debug("START");
  auto i = 0;
  const auto j = 0L;
  auto& r = i;  //
  auto pair = std::make_pair("a", 1);
  auto s = "";

  log_debug("variable auto");
  std::cout << i << std::endl;
  std::cout << j << std::endl;
  std::cout << r << std::endl;
  std::cout << pair.first << pair.second << std::endl;
  std::cout << s << std::endl;

  // return value
  auto result = sampleFunction();
  log_debug("return value for");
  std::cout << result << std::endl;
  //
  log_debug("namespace scope auto");
  log_debug("exnteded for");
  for (auto it = sample::v.begin(), e = sample::v.end(); it != e; ++it) {
    std::cout << *it << ",";
  }
  std::cout << std::endl;

  log_debug("if ");
  if (auto ptr = create_unique_ptr(1)) {
    std::cout << "success" << std::endl;

  } else {
    std::cout << "nullptr" << std::endl;
  }
  return 0;
}
