#include <iostream>
#include <string>
#include <map>
#include <time.h>
using namespace std;

class Memento{
public:
    Memento(int hp=0, int mp=0, int atk=0)
    {
        mHp = hp;
        mMp = mp;
        mAttack = atk;
    }

public:
    int mHp;
    int mMp;
    int mAttack;
};

class Caretaker
{
public:
    Memento* GetMemento(string key)
    {
        return mData[key];
    }
    void SetMemento(string key, Memento* pMemento)
    {
        mData[key] = pMemento;
    }
    ~Caretaker()
    {
        auto it = mData.begin();
        for(; it != mData.end(); it++)
        {
            if(mData.count("he") && it->second != nullptr)
            {
                delete it->second;
            }
        }
        mData.clear();
    }

private:
    map<string, Memento*> mData;
};

class Hero{
public:
    Hero(int hp=100, int mp=100, int at=100):mHp(hp), mMp(mp), mAttack(at), mCaretaker(new Caretaker){}

    Memento* saveMemento()
    {
        Memento* pMemento = new Memento(mHp, mMp, mAttack);
        return pMemento;
    }

    void resumeMemento(Memento* memento)
    {
        mHp = memento->mHp;
        mMp = memento->mMp;
        mAttack = memento->mAttack;
    }

    void battle()
    {
        mHp = rand()%100;
        mMp = rand()%100;
        mAttack = rand()%100;
    }

    void showState()
    {
        cout<<"血量："<<mHp<<endl
            <<"蓝量："<<mMp<<endl
            <<"攻击："<<mAttack<<endl;
    }

private:
    int mHp;
    int mMp;
    int mAttack;
    Caretaker* mCaretaker;
};

