class NetworkState {
 public:
  virtual ~NetworkState() = default;

  virtual void operation1() = 0;
  virtual void operation2() = 0;
  virtual void operation3() = 0;

  NetworkState* next() const { return next_; }

 protected:
  NetworkState* next_ = nullptr;
};

class NetworkOpenState : public NetworkState {
 public:
  // non-copyable
  NetworkOpenState(const NetworkOpenState&) = delete;
  NetworkOpenState& operator=(const NetworkOpenState&) = delete;

  // Handler to the Singleton class
  static NetworkState* Instance() {
    static NetworkOpenState instance;
    return &instance;
  }

  void operation1() override {
    // ***
    next_ = NetworCloseState::Instance();
  }

  void operation2() override {
    // ...
    next_ = NetworConnectState::Instance();
  }

  void operation3() override {
    // $$$
    next_ = NetworkOpenState::Instance();
  }

 private:
  NetworkOpenState() = default;
};

class NetworkCloseState : public NetworkState {
 public:
  void operation1() override;

  void operation2() override;

  void operation3() override;
};

class NetworkConnectState : public NetworkState {
 public:
  void operation1() override;

  void operation2() override;

  void operation3() override;
};

class NetworkProcessor {
 public:
  NetworkProcessor(NetworkState* state) : state_(state) {}

  void operation1() {
    // ...
    state_->operation1();
    state_ = state_->next();
    // ...
  }

  void operation2() {
    // ...
    state_->operation2();
    state_ = state_->next();
    // ...
  }

  void operation3() {
    // ...
    state_->operation3();
    state_ = state_->next();
    // ...
  }

 private:
  NetworkState* state_;
};
