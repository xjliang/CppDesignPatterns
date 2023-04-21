class Messager {
 public:
  virtual void login(string username, string password) = 0;
  virtual void sendMessage(string message) = 0;
  virtual void sendPicture(Image image) = 0;

  virtual void playSound() = 0;
  virtual void drawShape() = 0;
  virtual void writeText() = 0;
  virtual void connect() = 0;

  virtual ~Messager() {}
};


//平台实现

class PCMessagerBase : public Messager {
 public:
  void playSound() override {
    //**********
  }

  void drawShape() override {
    //**********
  }

  void writeText() override {
    //**********
  }

  void connect() override {
    //**********
  }
};

class MobileMessagerBase : public Messager {
 public:
  void playSound() override {
    //==========
  }

  void drawShape() override {
    //==========
  }

  void writeText() override {
    //==========
  }

  void connect() override {
    //==========
  }
};

// 业务抽象

class PCMessagerLite : public PCMessagerBase {
 public:
  void login(string username, string password) override {
    PCMessagerBase::connect();
    //........
  }

  void sendMessage(string message) override {
    PCMessagerBase::writeText();
    //........
  }

  void sendPicture(Image image) override {
    PCMessagerBase::drawShape();
    //........
  }
};

class PCMessagerPerfect : public PCMessagerBase {
 public:
  void login(string username, string password) override {
    PCMessagerBase::playSound();
    //********
    PCMessagerBase::connect();
    //........
  }

  void sendMessage(string message) override {
    PCMessagerBase::playSound();
    //********
    PCMessagerBase::writeText();
    //........
  }

  void sendPicture(Image image) override {
    PCMessagerBase::playSound();
    //********
    PCMessagerBase::drawShape();
    //........
  }
};


class MobileMessagerLite : public MobileMessagerBase {
 public:
  void login(string username, string password) override {
    MobileMessagerBase::connect();
    //........
  }
  void sendMessage(string message) override {
    MobileMessagerBase::writeText();
    //........
  }
  void sendPicture(Image image) override {
    MobileMessagerBase::drawShape();
    //........
  }
};

class MobileMessagerPerfect : public MobileMessagerBase {
 public:
  void login(string username, string password) override {
    MobileMessagerBase::playSound();
    //********
    MobileMessagerBase::connect();
    //........
  }

  void sendMessage(string message) override {
    MobileMessagerBase::playSound();
    //********
    MobileMessagerBase::writeText();
    //........
  }

  void sendPicture(Image image) override {
    MobileMessagerBase::playSound();
    //********
    MobileMessagerBase::drawShape();
    //........
  }
};


void Process(){
  // 编译时装配
  Messager* m = new MobileMessagerPerfect();
}