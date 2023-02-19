#include <iostream>

class Robot
{
public:
    virtual void doSomething() = 0;

};

class RobotV1 : public Robot
{
public:
    virtual void doSomething() override
    {
        std::cout << "�Ի�" << std::endl;
        std::cout << "������" << std::endl;
    }
//    ~RobotV1(){std::cout<<"1������";}
};


class RobotExtend : public Robot
{
private:
    Robot *robot_;
public:
    RobotExtend(Robot *robot)
    {
        robot_ = robot;
    }

    virtual void doSomething() override
    {
        robot_->doSomething();
    }

    void doMoreThing()
    {
        std::cout << "ɨ��" << std::endl;
        std::cout << "ϴ��" << std::endl;

    }
//    ~RobotExtend(){std::cout<<"2������";}
};

int main()
{
    RobotV1 v1 =RobotV1();
    std::cout << "��һ��������===========================" << std::endl;
    v1.doSomething();
    std::cout << "�Ե�һ��������չ===========================" << std::endl;
    RobotExtend v1_1=RobotExtend(&v1);
    v1_1.doSomething();
    v1_1.doMoreThing();

    return 0;
}
