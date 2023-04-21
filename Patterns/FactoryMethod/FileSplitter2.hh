// 具体类
class BinarySplitter : public ISplitter {

};

class TxtSplitter: public ISplitter {

};

class PictureSplitter: public ISplitter {

};

class VideoSplitter: public ISplitter {

};

// 具体工厂
class BinarySplitterFactory : public ISplitterFactory {
  ISplitter* createSplitter() override {
    return new BinarySplitter();
  }
};

class TxtSplitterFactory : public ISplitterFactory {
  ISplitter* createSplitter() override {
    return new TxtSplitter();
  }
};

class PictureSplitterFactory : public ISplitterFactory {
  ISplitter* createSplitter() override {
    return new PictureSplitter();
  }
};

class VideoSplitterFactory : public ISplitterFactory {
  ISplitter* createSplitter() override {
    return new VideoSplitter();
  }
};