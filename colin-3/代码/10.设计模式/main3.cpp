#include<iostream>
using namespace std;

/*
单例懒汉式:当调用创建单例的接口的时候,再创建这个唯一实例。(先用现搞)
单例饿汉式:当程序创建的时候，这个唯一的实例就一起创建了。(先搞预用)
*/

class Singleton {
private:
    //让构造函数是私有函
    Singleton(){}
    Singleton(const Singleton&) = delete;
    ~Singleton(){}
    //在类内创建单例

    //提供公共接口(用public修饰的接口)
    //Singleton* m_psin = nullptr; 错误写法
    //类的 static 成员变量不依赖对象存在，是所有类对象共享的 “全局变量”，需在类外单独初始化。
    static Singleton* m_psin;//这是类的变量 并不是某个对象的变量

    //
    class DelSingleton {
        ~DelSingleton() {
            Singleton::deleteSingleton();
        }
    };
    static DelSingleton delSin; //唯一的作用就是利用其析构函数调用的特点 来回收单例对象


public:
    //在单线程下创建没有问题 在多线程下可能会创建多个对象
    //todo: 待解决

    /*static 成员函数属于类本身，没有 this 指针，
    只能访问类的 static 成员（不能访问非 static 成员），可通过 类名::函数名 直接调用。*/
    static Singleton* createSingleton() {
        if (!m_psin) {//如果指针为空 那就说明没有创建过单例对象
            m_psin = new Singleton;
        }
        return m_psin;
    }

    static void deleteSingleton() {
        if (m_psin) {
            delete m_psin;
            m_psin = nullptr;
        }
    }
};
//静态属性，在类外定义及初始化
Singleton* Singleton::m_psin = nullptr;
Singleton::DelSingleton Singleton::delSin;

int main() {
    /*Singleton sin1;
    Singleton sin2;*/

    //Singleton sin1; //调用无参构造

    Singleton* psin1 = Singleton::createSingleton();

    //Singleton sin2(*psin1); //调用拷贝构造函数

    Singleton* psin2 = Singleton::createSingleton();

    cout << psin1 << "," << psin2 << endl;

    //delete psin2; //调用析构函数 但析构函数为私有的

    //静态函数可以用 类名作用域调用
    Singleton::deleteSingleton();
}
