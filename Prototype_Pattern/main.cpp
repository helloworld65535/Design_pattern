#include <iostream>


class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;
    virtual std::string whoAmI() = 0;
    virtual ~GermaSoldier() {}
};

class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier66(*this);
    }
    std::string whoAmI() override
    {
        return std::string("���ǽܶ���66�ĳ���ʿ��!!!");
    }
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone()
    {
        return new Soldier67(*this);
    }
    std::string whoAmI() override
    {
        return std::string("���ǽܶ���67�ĳ���ʿ��!!!");
    }
};


int main()
{
    GermaSoldier* obj = new Soldier66;
    GermaSoldier* soldier = obj->clone();
    std::cout << soldier->whoAmI() << std::endl;
    delete soldier;
    delete obj;

    obj = new Soldier67;
    soldier = obj->clone();
    std::cout << soldier->whoAmI() << std::endl;
    delete soldier;
    delete obj;
}
