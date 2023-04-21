// 对象表示
class House {
 public:
  friend class HouseBuilder;

  //....
};

// 对象构建
class HouseBuilder {
 public:
  House* build() {
    return house_;
  }

  virtual ~HouseBuilder() {}

 protected:
  House* house_;

	virtual void buildPart1() = 0;
  virtual void buildPart2() = 0;
  virtual void buildPart3() = 0;
  virtual void buildPart4() = 0;
  virtual void buildPart5() = 0;
};

class StoneHouse: public House {
};

class StoneHouseBuilder : public HouseBuilder {
 protected:
  virtual void buildPart1() {
    // house_->part1 = ...;
  }

  virtual void buildPart2() {
  }

  virtual void buildPart3() {
  }

  virtual void buildPart4() {
  }

  virtual void buildPart5() {
  }
};

class HouseDirector {
 public:
  HouseBuilder* house_builder_;

  HouseDirector(HouseBuilder* house_builder)
      : house_builder_(house_builder) {}

  House* construct() {
    house_builder_->buildPart1();
    for (int i = 0; i < 4; i++) {
      house_builder_->buildPart2();
    }
    bool flag = house_builder_->buildPart3();
    if (flag) {
      house_builder_->buildPart4();
    }
    house_builder_->buildPart5();
    return pHouseBuilder->build();
  }
};