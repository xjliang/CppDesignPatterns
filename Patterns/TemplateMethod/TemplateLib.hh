#include <iostream>

class Library {
 public:
  void run() {
    setup();
    step1();
    step2();
    teardown();
  }

  virtual ~Library() {}

 protected:
  void setup() {
    // stable
    std::cout << "setup ...\n";
  }

  void teardown() {
    // stable
    std::cout << "teardown ...\n";
  }

  virtual bool step1() = 0;  // change point 1
  virtual void step2() = 0;  // change point 2
};