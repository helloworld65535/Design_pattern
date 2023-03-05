#include <iostream>
using namespace std;

//租房接口
class Rent {
public:
    virtual void rent() = 0; //纯虚函数
};

//房东类，实现租房接口
class Host : public Rent {
public:
    void rent() override {
        cout << "房东出租房子" << endl;
    }
};

//中介类，也实现租房接口
class Proxy : public Rent {
private:
    Host* host; //持有真实角色的指针

public:
    Proxy(Host* host) {
        this->host = host;
    }

    void rent() override {
        seeHouse(); //调用真实角色之前的附加操作
        host->rent(); //调用真实角色的方法
        signContract(); //调用真实角色之后的附加操作
    }

    //看房子
    void seeHouse(){
        cout << "中介带你看房子" << endl;
    }

    //签合同
    void signContract(){
        cout << "签租赁合同" << endl;
    }
};

//客户端类，使用中介来租房子
int main() {
    
	Host* host = new Host(); //创建一个房东对象
	Proxy* proxy = new Proxy(host); //创建一个中介对象，并传入房东对象作为参数
	proxy->rent(); //通过中介来租房子，会有一些额外的服务
	
	delete proxy; 
	delete host;

	return 0;

	/*
	 * 输出：
	 * 中介带你看房子 
	 * 房东要出租房子 
	 * 签租赁合同 
	 */
}