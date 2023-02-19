#include <iostream>

struct Voltage
{
    unsigned int v;
    std::string t;
};

std::ostream &operator<<(std::ostream &out, const Voltage v)
{
    out << v.v << "V_" << v.t;
    return out;
}

class Output220_AC
{
public:
    virtual Voltage output220_AC() = 0;
};

//��һ������������Ľӿ����ṩ220V�Ľ�����
class Socket : public Output220_AC
{
private:
    Voltage voltage;
private:
    void check()
    {
        std::cout << "�����������е�" << std::endl;
        voltage.v = 220;
        voltage.t = "AC";
    }

public:
    virtual Voltage output220_AC() override
    {
        check();
        return voltage;
    }
};


class Output5V_DC
{
public:
    virtual Voltage output5V_DC() = 0;
};

class PowerAdapter : public Output5V_DC
{
private:
    Output220_AC *out;
public:
    PowerAdapter(Output220_AC *o)
    {
        out = o;
    }

    virtual Voltage output5V_DC() override
    {
        Voltage v = out->output220_AC();
        std::cout << "��Դ��������������" << std::endl;
//        ��ѹ����
        if (v.v >= 5)v.v = 5;
        if (v.t == "AC")v.t = "DC";
        return v;
    }
};

int main()
{
    Socket socket;
    std::cout << PowerAdapter(&socket).output5V_DC() << std::endl;
    return 0;
}
