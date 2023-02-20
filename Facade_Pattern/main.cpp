
#include <iostream>

// 各种智能家居构成一个子系统
// 由语音助手控制

class Light
{
public: /*公共*/
    Light(bool state, int luminance) : state_(state), luminance_(luminance) {}
    void setState(bool state) { state_ = state; }
    void setLuminance(int luminance) { luminance_ = luminance; }
    void show()
    {
        std::cout << "Light:[" << (state_?"on":"off") << ",luminance_:" << luminance_ << "%]" << std::endl;
    }

protected: /*保护*/
    bool state_;
    int luminance_;
};
class TV
{
public:
    TV() { state_ = 0; }
    void setState(bool state) { state_ = state; }
    void show()
    {
        std::cout << "TV:[" << (state_?"on":"off")<< "]" << std::endl;
    }

protected:
    bool state_;
};

class Ai
{
public:
    Ai(Light &light, TV &tv) : light_(light), tv_(tv) {}

    void watchTV()
    {
        std::cout << "当前状态：" << std::endl;
        light_.show();
        tv_.show();
        std::cout << "正在进入观影模式" << std::endl;
        light_.setState(1);
        light_.setLuminance(40);
        tv_.setState(1);
        std::cout << "已进入观影模式" << std::endl;
        light_.show();
        tv_.show();
    }

protected:
    Light &light_;
    TV &tv_;
};

int main(void)
{
    Light l(0,0);
    TV t;
    Ai a(l, t);
    a.watchTV();
    return 0;
}
