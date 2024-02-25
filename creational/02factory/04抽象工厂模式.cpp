// C++新经典的设计模式-抽象工厂-芭比娃娃例子
#include <iostream>

using namespace std;

// 身体抽象类
class Body
{
public:
    virtual void getName() = 0;
    virtual ~Body() {}
};
// 衣服抽象类

class Clothes
{
public:
    virtual void getName() = 0;
    virtual ~Clothes() {}
};
// 鞋子抽象类
class Shoes
{
public:
    virtual void getName() = 0;
    virtual ~Shoes() {}
};

// 芭比娃娃类
 class BarbieDoll
{
public:
    BarbieDoll(Body* body, Clothes* clothes, Shoes* shoes)
    {
        m_body = body;
        m_clothes = clothes;
        m_shoes = shoes;
    }

    void assemble()
    {
        cout << "成功组装了一个芭比娃娃" << endl;
        m_body->getName();
        m_clothes->getName();
        m_shoes->getName();
    }

private:
    Body* m_body;
    Clothes* m_clothes;
    Shoes* m_shoes;
};

// 中国厂商实现三个芭比娃娃部件生产
class ChinaBody:public Body
{
public:
    virtual void getName()override
    {
        cout << "中国厂商生产的身体部件" << endl;
    }
};


class ChinaClothes:public Clothes
{
public:
    virtual void getName()override
    {
        cout << "中国厂商生产的衣服部件" << endl;
    }
};


class ChinaShoes:public Shoes
{
public:
    virtual void getName()override
    {
        cout << "中国厂商生产的鞋子部件" << endl;
    }
};

// 日本厂商实现三个芭比娃娃部件生产
class JapanBody:public Body
{
public:
    virtual void getName()override
    {
        cout << "日本厂商生产的身体部件" << endl;
    }
};


class JapanClothes:public Clothes
{
public:
    virtual void getName()override
    {
        cout << "日本厂商生产的衣服部件" << endl;
    }
};


class JapanShoes:public Shoes
{
public:
    virtual void getName()override
    {
        cout << "日本厂商生产的鞋子部件" << endl;
    }
};


// 美国厂商实现三个芭比娃娃部件生产
class AmericanBody:public Body
{
public:
    virtual void getName()override
    {
        cout << "美国厂商生产的身体部件" << endl;
    }
};


class AmericanClothes:public Clothes
{
public:
    virtual void getName()override
    {
        cout << "美国厂商生产的衣服部件" << endl;
    }
};


class AmericanShoes:public Shoes
{
public:
    virtual void getName()override
    {
        cout << "美国厂商生产的鞋子部件" << endl;
    }
};

// 抽象工厂类
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}

public:
    virtual Body* createBody() = 0;  // 创建身体
    virtual Clothes* createClothes() = 0;  // 创建身体
    virtual Shoes* createShoes() = 0;  // 创建身体
};

// 创建一个中国工厂
class ChinaFactory:public AbstractFactory
{
public:
    virtual Body* createBody()override
    {
        return new ChinaBody;  
    }
    virtual Clothes* createClothes()override
    {
        return new ChinaClothes;
    }
    virtual Shoes* createShoes()override
    {
        return new ChinaShoes;
    }
};


// 创建一个日本工厂
class JapanFactory:public AbstractFactory
{
public:
    virtual Body* createBody()override
    {
        return new JapanBody;  
    }
    virtual Clothes* createClothes()override
    {
        return new JapanClothes;
    }
    virtual Shoes* createShoes()override
    {
        return new JapanShoes;
    }
};




// 创建一个美国工厂
class AmericanFactory:public AbstractFactory
{
public:
    virtual Body* createBody()override
    {
        return new AmericanBody;  
    }
    virtual Clothes* createClothes()override
    {
        return new AmericanClothes;
    }
    virtual Shoes* createShoes()override
    {
        return new AmericanShoes;
    }
};




int main()
{
    // 创建第一个完全中国产的芭比娃娃
    // 1. 先建立中国工厂
    AbstractFactory* pChinaFactory = new ChinaFactory();
    // 2.创建身体、衣服、鞋子
    Body* chinaBody = pChinaFactory->createBody();
    Clothes* chinaClothes = pChinaFactory->createClothes();
    Shoes* chinaShoes = pChinaFactory->createShoes();
    // 3.组装芭比娃娃
    BarbieDoll tmpObj(chinaBody, chinaClothes, chinaShoes);
    tmpObj.assemble();

    // 创建第二个芭比娃娃，混合血脉
    AbstractFactory* pJapanFactory = new JapanFactory();
    AbstractFactory* pAmericanFactory = new AmericanFactory();
    // 创建中国的身体(前面已经存在)，日本的衣服，美国的鞋子

    Clothes* JapanClothes = pJapanFactory->createClothes();
    Shoes* AmericanShoes = pAmericanFactory->createShoes();
    // 组装混血
    BarbieDoll mixBarbieDoll(chinaBody, JapanClothes, AmericanShoes);
    mixBarbieDoll.assemble();
    return 0;
}
