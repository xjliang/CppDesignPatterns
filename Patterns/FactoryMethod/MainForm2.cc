#include "FileSplitter1.hh"

class MainForm : public Form {
  SplitterFactory* factory_;

 public:
  MainForm(SplitterFactory* factory) : factory_(factory) {}

	void Button1_Click() {
		ISplitter * splitter = factory_->createSplitter(); // 依赖抽象类
    splitter->split();
	}
};