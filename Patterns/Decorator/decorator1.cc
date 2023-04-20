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
class CryptoFileStream : public FileStream {
 public:
  char read(int number) override {
    // extra crypto operation ...
    return FileStream::read(number);  // read file stream
  }

  void seek(int pos) override {
    // extra crypto operation ...
    FileStream::seek(pos);  // seek file stream
    // extra crypto operation ...
  }

  void write(char data) override {
    // extra crypto operation ...
    FileStream::write(data);  // write file stream
    // extra crypto operation ...
  }
};

class CryptoNetworkStream : public NetworkStream {
 public:
  char read(int number) override {
    // extra crypto operation ...
    return NetworkStream::read(number);  // read network stream
  }

  void seek(int pos) override {
    // extra crypto operation ...
    NetworkStream::seek(pos);  // seek network stream
    // extra crypto operation ...
  }

  void write(char data) override {
    // extra crypto operation ...
    NetworkStream::write(data);  // write network stream
    // extra crypto operation ...
  }
};

class CryptoMemoryStream : public MemoryStream {
 public:
  char read(int number) override {
    // extra crypto operation ...
    return MemoryStream::read(number);  // read memory stream
  }

  void seek(int pos) override {
    // extra crypto operation ...
    MemoryStream::seek(pos);  // seek memory stream
    // extra crypto operation ...
  }

  void write(char data) override {
    // extra crypto operation ...
    MemoryStream::write(data);  // write memory stream
    // extra crypto operation ...
  }
};

class BufferedFileStream : public FileStream {
  // ...
};

class BufferedNetworkStream : public NetworkStream {
  // ...
};

class BufferedMemoryStream : public MemoryStream {
  // ...
};

class CryptoBufferedFileStream : public FileStream {
 public:
  char read(int number) override {
    // extra crypto operation ...
    // extra buffering operation ...
    return FileStream::read(number);  // read file stream
  }

  void seek(int pos) override {
    // extra crypto operation ...
    // extra buffering operation ...
    FileStream::seek(pos);  // seek file stream
    // extra crypto operation ...
    // extra buffering operation ...
  }

  void write(char data) override {
    // extra crypto operation ...
    // extra buffering operation ...
    FileStream::write(data);  // write file stream
    // extra crypto operation ...
    // extra buffering operation ...
  }
};

int main() {
  // compile time
  CryptoFileStream* fs1 = new CryptoFileStream();
  BufferedFileStream* fs2 = new BufferedFileStream();
  CryptoBufferedFileStream* fs3 = new CryptoBufferedFileStream();
  delete fs1;
  delete fs2;
  delete fs3;
  std::cout << "done\n";

  return 0;
}