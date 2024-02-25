#include<iostream>
using namespace std;

class AbstractSmile
{
public:
    virtual void trasnform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile() {}

};
// 恶魔果实：绵羊形态
class SheepSmile:public AbstractSmile
{
public:
     void trasnform()override
     {
         cout << "变成人兽--绵羊人形态" << endl;
     }
     void ability()override
     {
         cout << "将手臂变成羊角招式--巨羊角" << endl;
     }
};

// 恶魔果实：狮子形态
class LionSmile:public AbstractSmile
{
public:
     void trasnform()override
     {
         cout << "变成人兽--狮子形态" << endl;
     }
     void ability()override
     {
         cout << "河东狮吼" << endl;
     }
};

// 恶魔果实：蝙蝠形态
class BatSmile:public AbstractSmile
{
public:
     void trasnform()override
     {
         cout << "变成人兽--蝙蝠形态" << endl;
     }
     void ability()override
     {
         cout << "吸血大法" << endl;
     }
};

//抽象工厂类
class AbstractFactory
{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() {}
};

// 生产绵羊恶魔果实的工厂
class SheepFactory:public AbstractFactory
{
public:
    AbstractSmile* createSmile()override
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout << "释放SheepFactory相关资源" << endl;
    }
};


// 生产狮子恶魔果实的工厂
class LionFactory:public AbstractFactory
{
public:
    AbstractSmile* createSmile()override
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout << "释放LionFactory相关资源" << endl;
    }
};

// 生产蝙蝠恶魔果实的工厂
class BatFactory:public AbstractFactory
{
public:
    AbstractSmile* createSmile()override
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        cout << "释放BatFactory相关资源" << endl;
    }
};


int main()
{
    AbstractFactory* factory = new LionFactory;
    AbstractSmile* smile = factory->createSmile();
    smile->trasnform();
    smile->ability();
    return 0;
}
