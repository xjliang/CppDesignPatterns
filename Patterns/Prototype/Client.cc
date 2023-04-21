class MainForm : public Form {
  ISplitter* prototype_; // 原型对象

 public:
  MainForm(ISplitter*  prototype) : prototype_(prototype) {}

	void Button1_Click() {
	  ISplitter* splitter = prototype->clone(); // 克隆原型
    splitter->split();
	}
};