#include <iostream>

// business operation
class Stream {
 public:
  virtual char read(int number) = 0;
  virtual void seek(int pos) = 0;
  virtual void write(char data) = 0;

  virtual ~Stream() = default;
};

// subject class
class FileStream : public Stream {
 public:
  char read(int number) override {
    // read file stream ...
    return 'c';
  }

  void seek(int pos) override {
    // seek file stream ...
  }

  void write(char data) override {
    // write file stream ...
  }
};

class NetworkStream : public Stream {
 public:
  char read(int number) override {
    // read network stream ...
    return 'c';
  }

  void seek(int pos) override {
    // seek network stream ...
  }

  void write(char data) override {
    // write network stream ...
  }
};

class MemoryStream : public Stream {
 public:
  char read(int number) override {
    // read memory stream ...
    return 'c';
  }

  void seek(int pos) override {
    // seek memory stream ...
  }

  void write(char data) override {
    // write memory stream ...
  }
};

// extension operations
class CryptoStream : public Stream {
  Stream* stream_; // = new xxxStream;

 public:
  CryptoStream(Stream* stream) : stream_(stream) {}

  char read(int number) override {
    // extra crypto operation ...
    return stream_->read(number);  // read stream
  }

  void seek(int pos) override {
    // extra crypto operation ...
    stream_->seek(pos);  // seek stream
    // extra crypto operation ...
  }

  void write(char data) override {
    // extra crypto operation ...
    stream_->write(data);  // write stream
    // extra crypto operation ...
  }
};

class BufferedStream : public Stream {
  Stream* stream_; // = new xxxStream;

 public:
  BufferedStream(Stream* stream) : stream_(stream) {}

  char read(int number) override {
    // extra buffering operation ...
    return stream_->read(number);  // read stream
  }

  void seek(int pos) override {
    // extra buffering operation ...
    stream_->seek(pos);  // seek stream
    // extra buffering operation ...
  }

  void write(char data) override {
    // extra buffering operation ...
    stream_->write(data);  // write stream
    // extra buffering operation ...
  }
};

int main() {
  // run time
  FileStream* s1 = new FileStream();
  CryptoStream* s2 = new CryptoStream(s1);
  BufferedStream* s3 = new BufferedStream(s1);
  BufferedStream* s4 = new BufferedStream(s2);

  delete s1;
  delete s2;
  delete s3;
  delete s4;
  std::cout << "done\n";

  return 0;
}