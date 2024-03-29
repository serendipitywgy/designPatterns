#include <iostream>
using namespace std;

// 产品类的父类-人造恶魔果实
class AbstractSmile {
public:
  virtual void transform() = 0;
  virtual void ability() = 0;
  virtual ~AbstractSmile() {}
};

// 人造恶魔果实-绵羊形态
class SheepSmile : public AbstractSmile {
public:
  void transform() override { cout << "变成人兽 -- 山羊形态..." << endl; }
  void ability() override {

    cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
  }
};

// 人造恶魔果实-狮子形态
class LionSmile : public AbstractSmile {
public:
  void transform() override { cout << "变成人兽 -- 狮子形态..." << endl; }
  void ability() override { cout << "火遁-豪火球之术..." << endl; }
};

class BatSmile : public AbstractSmile {
public:
  void transform() override { cout << "变成人兽 -- 蝙蝠人形态..." << endl; }
  void ability() override { cout << "声纳引箭之万剑归宗..." << endl; }
};

// 恶魔果实工厂
enum class Type : char { SHEEP, LION, BAT };
class SmileFactory {
public:
  SmileFactory() {}
  ~SmileFactory() {}

  AbstractSmile *createSmile(Type type) {
    AbstractSmile *ptr = nullptr;
    switch (type) {
    case Type::SHEEP:
      ptr = new SheepSmile();
      break;
    case Type::LION:
      ptr = new LionSmile();
      break;
    case Type::BAT:
      ptr = new BatSmile();
      break;
    default:

      break;
    }
    return ptr;
  }
};

int main() {
  SmileFactory *factory = new SmileFactory();
  AbstractSmile *obj = factory->createSmile(Type::LION);
  obj->transform();
  obj->ability();
}
