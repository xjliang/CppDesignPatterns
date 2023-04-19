#include <iostream>

class Library {
 public:
  void setup() {
    // stable
    std::cout << "setup ...\n";
  }

  void teardown() {
    // stable
    std::cout << "teardown ...\n";
  }
};