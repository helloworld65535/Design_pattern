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
        std::cout << "对话" << std::endl;
        std::cout << "放音乐" << std::endl;
    }
//    ~RobotV1(){std::cout<<"1析构了";}
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
        std::cout << "扫地" << std::endl;
        std::cout << "洗碗" << std::endl;

    }
//    ~RobotExtend(){std::cout<<"2析构了";}
};

int main()
{
    RobotV1 v1 =RobotV1();
    std::cout << "第一代机器人===========================" << std::endl;
    v1.doSomething();
    std::cout << "对第一代进行扩展===========================" << std::endl;
    RobotExtend v1_1=RobotExtend(&v1);
    v1_1.doSomething();
    v1_1.doMoreThing();

    return 0;
}
