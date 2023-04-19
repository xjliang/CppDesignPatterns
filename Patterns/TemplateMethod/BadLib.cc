#include "BadLib.hh"

class App {
 public:
  bool step1() {
    std::cout << "running step1 in app ...\n";
  }

  void step2() {
    std::cout << "running step2 in app ...\n";
  }
};

int main(int argc, char* argv[]) {
  Library lib;
  App app;
  lib.setup();
  app.step1();
  app.step2();
  lib.teardown();
  return 0;
}