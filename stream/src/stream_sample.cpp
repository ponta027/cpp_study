#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>

class TestErrorException {
 private:
  std::string message;

 public:
  TestErrorException(std::string msg) : message(msg){};
  std::string toString() { return message; }
};
static void assertEqual(int expect, int actual) {
  if (expect != actual) {
    std::stringstream ss;
    ss << "assert Error:expect=";
    ss << expect;
    ss << "actual=";
    ss << actual;
    throw TestErrorException(ss.str());
  }
}
static void assertEqual(std::string expect, std::string actual) {
  if (expect != actual) {
    std::stringstream ss;
    ss << "assert Error:expect=";
    ss << expect;
    ss << "actual=";
    ss << actual;
    throw TestErrorException(ss.str());
  }
}

class Test {
  enum ResultCode { OK, NG };

 private:
  ResultCode result = ResultCode::OK;

 protected:
  virtual std::string getTestName() = 0;

 public:
  virtual void setup() { std::cout << "[SETUP]" << std::endl; };
  virtual void teadown() { std::cout << "[TEARDOWN]" << std::endl; };
  virtual void execute() = 0;
  void test(void) {
    std::cout << "TEST CASE:";
    std::cout << getTestName() << std::endl;
    

    setup();
    try {
      execute();
    } catch (TestErrorException& e) {
      result = ResultCode::NG;
      std::cout << e.toString() << std::endl;
    } catch (...) {
      result = ResultCode::NG;
    }
    std::cout << (result == ResultCode::OK ? ":OK" : ":NG") << std::endl;
    teadown();
  }
};

class StringStreamTest : public Test {
 protected:
  std::string getTestName() override { return typeid(*this).name(); }

 public:
  void execute() override {
    std::cout << "[EXECUTE]" << std::endl;
    /**
     * ios_base <- ios <- istream <-iostream <-stringstream
     * 	         <- ostream
     */
    {
      std::stringstream ss;
      std::string str = "test ";
      int num = 40;
      ss << num << str;
      assertEqual("40test ", ss.str());
      int tmp;
      ss >> tmp;
      assertEqual(40, tmp);
    }
    {
      std::string output;
      std::stringstream ss;
      ss << "test" << std::endl << 40;
      std::getline(ss, output);
      assertEqual("test", output);
      std::getline(ss, output);
      assertEqual("40", output);
    }
  };
};

class IOStreamTest : public Test {
 protected:
  std::string getTestName() override { return typeid(*this).name(); }

 public:
  void execute() override {
    std::cout << "[EXECUTE]" << std::endl;
    std::stringstream org;
    org << "hello" << std::endl;
    org << "world" << std::endl;

    {
      std::ofstream ofs("test.txt");
      std::string str;
      while (std::getline(org, str)) {
	ofs << str << std::endl;
      }
    }  // call close when object destroyed.
    {
      std::ifstream ifs("test.txt");
      std::string str;
      std::stringstream ss;
      while (getline(ifs, str)) {
	ss << str << std::endl;
      }
      assertEqual(ss.str(), org.str());
    }
  };
};

int main(int argc, char* argv[]) {  //

  Test* test[] = {new StringStreamTest(), new IOStreamTest()};

  for (auto it : test) {
    it->test();
  }

  for (auto it : test) {
    delete it;
  }
  return 0;
}
