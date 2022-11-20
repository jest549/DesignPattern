#include <iostream>

using namespace std;

class Prototype {
public:
    Prototype() 
    {

    }

    virtual ~Prototype() { }

    virtual Prototype* clone() = 0;
protected: 

};

class ConcretePrototype : public Prototype 
{
public:
    ConcretePrototype(int size) : m_counter(0),m_buff_size(size)
    { 
        m_buffer =new char[size];
    }
    ~ConcretePrototype() { }

    ConcretePrototype(const ConcretePrototype& rhs) {
        m_counter = rhs.m_counter;
        m_buffer =new char[rhs.m_buff_size];
        m_buff_size =rhs.m_buff_size;
    }

    Prototype* clone() override {
        cout <<"ConcretePrototype: clone myself"<<std::endl;
        return new ConcretePrototype(*this);
    }

private: 
    int m_counter;
    char* m_buffer;
    int m_buff_size;

};

