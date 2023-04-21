enum NetworkState {
  kNetworkOpen,
  kNetworkClose,
  kNetworkConnect
};

class NetworkProcessor {
 public:
  void Operation1() {
    if (state == kNetworkOpen) {
      //***
      state = kNetworkClose;
    } else if (state == kNetworkClose) {
      //...
      state = kNetworkConnect;
    } else if (state == kNetworkConnect) {
      //$$$
      state = kNetworkOpen;
    }
  }

  void Operation2() {
    if (state == kNetworkOpen) {
      // ***
      state = kNetworkConnect;
    } else if (state == kNetworkClose) {
      // ...
      state = kNetworkOpen;
    } else if (state == kNetworkConnect) {
      // $$$
      state = kNetworkClose;
    }
  }

  void Operation3() {

  }

 private:
  NetworkState state;
};
