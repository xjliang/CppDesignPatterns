// C++11
#include <iostream>
#include <list>
#include <string>

class IObserver {
 public:
  virtual ~IObserver() = default;
  virtual void update(const std::string& msg) = 0;
};

class ISubject {
 public:
  virtual ~ISubject() = default;
  virtual void attach(IObserver* observer) = 0;
  virtual void detach(IObserver* observer) = 0;
  virtual void notify() = 0;
};

class Subject : public ISubject {
 public:
  virtual ~Subject() {
    std::cout << "Goodbye, I was the Subject.\n";
  }

  void attach(IObserver* observer) override {
    observer_list_.push_back(observer);
  }

  void detach(IObserver* observer) override {
    observer_list_.remove(observer);
  }

  void notify() override {
    std::cout << "There are " << observer_list_.size() << " observers in the list.\n";
    for (auto o : observer_list_) {
      o->update(msg_);
    }
  }

  void setMsg(const std::string& msg = "empty") {
    msg_ = msg;
    notify();
  }

  void run() {
    msg_ = "change message";
    notify();
    std::cout << "running ...\n";
  }

 private:
  std::list<IObserver*> observer_list_;
  std::string msg_;
};

class Observer : public IObserver {
 public:
  Observer(Subject* subject) : subject_(subject) {
    subject_->attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::scnt_ << "\".\n";
    cnt_ = Observer::scnt_;
  }

  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << cnt_ << "\".\n";
  }

  void update(const std::string& msg) override {
    msg_ = msg;
    printInfo();
  }

  void unsubstribe() {
    subject_->detach(this);
    std::cout << "Observer \"" << cnt_ << "\" removed from the list.\n";
  }

  void printInfo() const {
    std::cout << "Observer \"" << cnt_ << "\": a new message is available --> " << msg_ << "\n";
  }

 private:
  Subject* subject_;
  std::string msg_;  // message from subject
  static int scnt_;
  int cnt_;
};

int Observer::scnt_ = 0;

int main(int argc, char* argv[]) {
  Subject* subject = new Subject;
  Observer* obs1 = new Observer(subject);
  Observer* obs2 = new Observer(subject);
  Observer* obs3 = new Observer(subject);
  Observer* obs4;
  Observer* obs5;

  subject->setMsg("Hello World! :D");
  obs3->unsubstribe();

  subject->setMsg("The weather is hot today! :p");
  obs4 = new Observer(subject);

  obs2->unsubstribe();
  obs5 = new Observer(subject);

  subject->setMsg("My new car is greaty! :)");
  obs5->unsubstribe();

  obs4->unsubstribe();
  obs1->unsubstribe();

  delete obs5;
  delete obs4;
  delete obs3;
  delete obs2;
  delete obs1;
  delete subject;

  return 0;
}

// Hi, I'm the Observer "1".
// Hi, I'm the Observer "2".
// Hi, I'm the Observer "3".
// There are 3 observers in the list.
// Observer "1": a new message is available --> Hello World! :D
// Observer "2": a new message is available --> Hello World! :D
// Observer "3": a new message is available --> Hello World! :D
// Observer "3" removed from the list.
// There are 2 observers in the list.
// Observer "1": a new message is available --> The weather is hot today! :p
// Observer "2": a new message is available --> The weather is hot today! :p
// Hi, I'm the Observer "4".
// Observer "2" removed from the list.
// Hi, I'm the Observer "5".
// There are 3 observers in the list.
// Observer "1": a new message is available --> My new car is greaty! :)
// Observer "4": a new message is available --> My new car is greaty! :)
// Observer "5": a new message is available --> My new car is greaty! :)
// Observer "5" removed from the list.
// Observer "4" removed from the list.
// Observer "1" removed from the list.
// Goodbye, I was the Observer "5".
// Goodbye, I was the Observer "4".
// Goodbye, I was the Observer "3".
// Goodbye, I was the Observer "2".
// Goodbye, I was the Observer "1".
// Goodbye, I was the Subject.