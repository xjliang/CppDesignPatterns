#include <iostream>
#include <memory>  // unique_ptr

struct Context {
  // TBD
};

class TaxStrategy {
 public:
  virtual double calculate(const Context& context) = 0;
  virtual ~TaxStrategy() {}
};

class CNTaxStrategy : public TaxStrategy {
 public:
  double calculate(const Context& context) override {
    // do something
    std::cout << "CNTax calculated.\n";
    return 1.0;
  }
};

class USTaxStrategy : public TaxStrategy {
 public:
  double calculate(const Context& context) override {
    // do something
    std::cout << "USTax calculated.\n";
    return 1.0;
  }
};

class DETaxStrategy : public TaxStrategy {
 public:
  double calculate(const Context& context) override {
    // do something
    std::cout << "DETax calculated.\n";
    return 1.0;
  }
};

// more strategy can be added here.

class SalesOrder {
 public:
  SalesOrder(std::unique_ptr<TaxStrategy> strategy)
      : strategy_calculator_(std::move(strategy)) {}

  void setCalculater(std::unique_ptr<TaxStrategy> strategy) {
    strategy_calculator_ = std::move(strategy);
  }

  double calculateTax() {
    // ...
    Context context;
    double val = strategy_calculator_->calculate(context);
    // ...
    return val;
  }

 private:
  std::unique_ptr<TaxStrategy> strategy_calculator_;
};

int main(int argc, char* argv[]) {
  SalesOrder sale(std::make_unique<CNTaxStrategy>());
  sale.calculateTax();

  std::cout << "switching to USTaxStrategy ..\n";
  sale.setCalculater(std::make_unique<USTaxStrategy>());
  sale.calculateTax();
  return 0;
}