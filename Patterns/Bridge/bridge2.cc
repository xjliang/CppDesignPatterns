#include <iostream>
#include <string>

struct Image {
};

class MessagerImpl {
 public:
  virtual void playSound() = 0;
  virtual void drawShape() = 0;
  virtual void writeText() = 0;
  virtual void connect() = 0;

  virtual ~MessagerImpl() {}
};

class Messager {
 public:
  Messager(MessagerImpl* messager_impl) : messager_impl_(messager_impl) {}

  virtual void login(std::string username, std::string password) = 0;
  virtual void sendMessage(std::string message) = 0;
  virtual void sendPicture(Image image) = 0;

  virtual ~Messager() {}

 protected:
  MessagerImpl* messager_impl_;
};

// 平台实现

class PCMessagerImpl : public MessagerImpl {
 public:
  void playSound() override {
    //**********
    std::cout << "PC playSound ...\n";
  }

  void drawShape() override {
    //**********
    std::cout << "PC drawShape ...\n";
  }

  void writeText() override {
    //**********
    std::cout << "PC writeText ...\n";
  }

  void connect() override {
    //**********
    std::cout << "PC connect ...\n";
  }
};

class MobileMessagerImpl : public MessagerImpl {
 public:
  void playSound() override {
    //==========
    std::cout << "Mobile playSound ...\n";
  }

  void drawShape() override {
    //==========
    std::cout << "Mobile drawShape ...\n";
  }

  void writeText() override {
    //==========
    std::cout << "Mobile writeText ...\n";
  }

  void connect() override {
    //==========
    std::cout << "Mobile connect ...\n";
  }
};

// 业务抽象

class MessagerLite : public Messager {
 public:
  MessagerLite(MessagerImpl* impl) : Messager(impl) {}

  void login(std::string username, std::string password) override {
    std::cout << "[Lite] login ...\n";
    messager_impl_->connect();
    //........
  }

  void sendMessage(std::string message) override {
    std::cout << "[Lite] sendMessage ...\n";
    messager_impl_->writeText();
    //........
  }

  void sendPicture(Image image) override {
    std::cout << "[Lite] sendPicture ...\n";
    messager_impl_->drawShape();
    //........
  }
};

class MessagerPerfect : public Messager {
 public:
  MessagerPerfect(MessagerImpl* impl) : Messager(impl) {}

  void login(std::string username, std::string password) override {
    std::cout << "[Perfect] login ...\n";
    messager_impl_->playSound();
    //********
    messager_impl_->connect();
    //........
  }

  void sendMessage(std::string message) override {
    std::cout << "[Perfect] sendMessage ...\n";
    messager_impl_->playSound();
    //********
    messager_impl_->writeText();
    //........
  }

  void sendPicture(Image image) override {
    std::cout << "[Perfect] sendPicture ...\n";
    messager_impl_->playSound();
    //********
    messager_impl_->drawShape();
    //........
  }
};


void Process() {
  // 运行时装配
  MessagerImpl* impl = new MobileMessagerImpl();
  Messager* messager = new MessagerPerfect(impl);

  messager->login("hunter", "123456");
  messager->sendMessage("Hello World!");
  Image img;
  messager->sendPicture(img);

  delete messager;
  delete impl;
}

int main(int argc, char* argv[]) {
  Process();
  return 0;
}