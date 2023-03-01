#include<iostream>
using namespace std;

class State;
class ForenoonState;
class NoonState;
class AfternonnState;
class EveningState;
class SleepingState;
class RestState;
class Work;

// 抽象状态角色，负责定义各个状态有哪些行为，该抽象状态包含所有具体状态的方法。并且封装环境角色，帮助切换状态。
class State
{
public:
    State():m_hour(0){}
    virtual void writeprogram() = 0;
    virtual ~State() = default;
    int getState(){return m_hour;}
protected:
    int m_hour;
};
// Context 角色，在该类内部维护一个ConcreteState子类的一个实例，可以负责具体状态的切换
class Work
{
private:
    State* current;

public:
    Work();
    ~Work();
    void SetState(State* s)
    {
        delete current;
        current = s;
    }
    int getState()
    {
        return current->getState();
    }
    void WorkProgram()
    {
        current->writeprogram();
    }
};

// 下面都是具体的状态类，每一个具体状态类必须完成两个职责：该类本状态下要做的事情，以及如何执行到其他具体状态类的状态。
class ForenoonState :public State
{
private:
using State::m_hour;
public:
    ForenoonState()
    {
        m_hour=8;
    }
    void writeprogram()override;

};

class NoonState :public State
{
public:
    NoonState()
    {
        State::m_hour=12;
    }
    void writeprogram()override;
};

class AfternoonState :public State
{
public:
    AfternoonState()
    {
        State::m_hour=16;
    }
    void writeprogram()override;
};

class EveningState :public State
{
public:
    EveningState()
    {
        State::m_hour=20;
    }
    void writeprogram()override;
};

class SleepingState :public State
{// 睡眠状态
public:
    SleepingState()
    {
        State::m_hour=24;
    }
    void writeprogram()override;

};



Work::Work()
{
    current = new ForenoonState();
}
Work::~Work()
{
    delete current;
}

void ForenoonState::writeprogram()
{

    cout << "当前时间：" << m_hour << "点，上午工作，精神百倍" << endl;
}

void NoonState::writeprogram()
{
    cout << "当前时间：" << m_hour << "点，吃午饭，睡午觉" << endl;

    
}

void AfternoonState::writeprogram()
{
    cout << "当前时间：" << m_hour << "点，下午状态还不错，吃个下午茶" << endl;

}

void EveningState::writeprogram()
{

    cout << "当前时间：" << m_hour << "点,晚上加班累了，下班 " << endl;

}

void SleepingState::writeprogram()
{
    cout << "当前时间：" << m_hour << "点,不能再high了，要睡了 " << endl;
}
