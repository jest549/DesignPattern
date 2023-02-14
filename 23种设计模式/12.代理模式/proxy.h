

#include <iostream>
#include<string>
#include<map>
using namespace std;//Subject
class Person 
{
public:
    virtual string rentHouse() = 0;
    virtual  string getName()=0;

};

//RealSubject
class Tom :public  Person {
public:
    Tom(): m_name("Tom")
    {

    }
    string rentHouse() {
        return string("租一间两房一厅房子");
    }
    string getName()
    {
        return m_name;
    }
    private :
    string m_name;
};

//Proxy
class Proxy :public Person {
public:
    Proxy(Person* person) :m_Person(person) ,m_name("中介"){}
    string rentHouse() {
        string str=string("代理人:")+getName()+"\n";
        str=str+string("发起人:")+m_Person->getName()+"\n";
        str=str+string("需求:")+m_Person->rentHouse()+"\n";
        //对RealSubject实体的rentHouse找一个房子
        str=str+string("结果:")+string("代理人已经找到合适房子!");
        cout <<str<<endl;
        return str;

    }
    string getName()
    {
        return m_name;
    }
private:
    Person* m_Person;
    string m_name;
};

