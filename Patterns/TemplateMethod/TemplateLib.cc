#include "TemplateLib.hh"

class App : public Library {
 public:
  bool step1() override {
    std::cout << "running step1 in app ...\n";
  }

  void step2() override {
    std::cout << "running step2 in app ...\n";
  }
};

int main(int argc, char* argv[]) {
  App app;
  app.run();
  return 0;
}