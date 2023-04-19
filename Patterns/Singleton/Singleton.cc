// C++11
#include <iostream>
#include <atomic>
#include <mutex>

namespace detail::impl1 {

// Meyer's Singleton: static local object
class Singleton {
 public:
  // non-copyable
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton& Instance() {
    static Singleton instance;  // thread-safe in C++11
    return instance;
  }

  void run() {
    std::cout << "Singleton1::run()...\n";
  }

 protected:
  Singleton() = default;
};

} // namespace detail::impl1


namespace detail::impl2 {

class Singleton {
 public:
  // non-copyable
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* Instance() {
    Singleton* res = instance_.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (res == nullptr) {
      std::lock_guard<std::mutex> lock(mutex_);
      res = instance_.load(std::memory_order_relaxed);
      if (res == nullptr) {
        res = new Singleton;
        std::atomic_thread_fence(std::memory_order_release);
        instance_.store(res, std::memory_order_relaxed);
      }
    }
    return res;
  }

  void run() {
    std::cout << "Singleton2::run()...\n";
  }

 protected:
  Singleton() = default;

  static std::atomic<Singleton*> instance_;
  static std::mutex mutex_;
};

std::atomic<Singleton*> Singleton::instance_;
std::mutex Singleton::mutex_;

} // namespace detail::impl2

int main(int argc, char* argv[]) {
  detail::impl1::Singleton::Instance().run();
  detail::impl2::Singleton::Instance()->run();
  return 0;
}