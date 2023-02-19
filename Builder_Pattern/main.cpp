#include <iostream>

// 假如要建一个房子
typedef std::string House;

class HouseBuilder
{
public:
    House *getResult()
    {
        return pHouse_;
    }
    virtual ~HouseBuilder() {}
    virtual void BuildFoundation(int width) = 0; ///< 建造地基
    virtual void BuildFloor(int width) = 0;      ///< 建造楼层
    virtual void BuildRoof(int width) = 0;       ///< 建造屋顶
protected:
    House *pHouse_;
};

class MyHouseBuilder :public HouseBuilder
{
public:
    MyHouseBuilder(House *pHouse)
    {
        pHouse_ = pHouse;
    }
    virtual void BuildFoundation(int width) override
    {
        (*pHouse_) += std::string(width, '#');
        (*pHouse_) += '\n';
    }
    virtual void BuildFloor(int width) override
    {
        (*pHouse_) += std::string(width, '-');
        (*pHouse_) += '\n';
        (*pHouse_) += '|';
        if (width >= 2)
            (*pHouse_) += std::string(width - 2, ' ');
        (*pHouse_) += "|\n";
        (*pHouse_) += std::string(width, '-');
        (*pHouse_) += '\n';
    }
    virtual void BuildRoof(int width) override
    {
        int high = width / 2 - 1;
        for (size_t i = 0; i <= high; i++)
        {
            std::string temp(width, ' ');
            temp[high - i] = '/';
            temp[(width - 1 - (high - i))] = '\\';
            (*pHouse_) += temp;
            (*pHouse_) += '\n';
        }
    }
};

class HouseDirector
{
public:
    HouseDirector(HouseBuilder *pHouseBuilder, int width = 0)
        : pHouseBuilder_(pHouseBuilder), width_(width)
    {
    }

    House *Construct()
    {
        if (width_ >= 2)
        {
            pHouseBuilder_->BuildRoof(width_);
            pHouseBuilder_->BuildFloor(width_);
            pHouseBuilder_->BuildFoundation(width_);
        }
        return pHouseBuilder_->getResult();
    }

private:
    HouseBuilder *pHouseBuilder_;
    int width_;
};

int main()
{
    House *myHouse = new House();
    HouseBuilder *builder = new MyHouseBuilder(myHouse);
    myHouse = HouseDirector(builder, 2).Construct();
    std::cout << *myHouse;
    delete myHouse;
    delete builder;
    return 0;
}
