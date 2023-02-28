#include "memento.h"

int main()
{
    srand((unsigned int) time(NULL));

    Caretaker ctk;
    Hero hero;
    Memento mmt;

    cout<<"----战斗前-----"<<endl;
    hero.showState();
    cout<<endl;
    ctk.SetMemento("战斗前",hero.saveMemento());

    hero.battle();
    cout<<"-----战斗1后-----"<<endl;
    hero.showState();
    cout<<endl;
    ctk.SetMemento("战斗1后",hero.saveMemento());

    hero.battle();
    cout<<"-----战斗2后-----"<<endl;
    hero.showState();
    ctk.SetMemento("战斗2后",hero.saveMemento());
    cout<<endl;

    hero.battle();
    cout<<"-----战斗3后-----"<<endl;
    hero.showState();
    ctk.SetMemento("战斗3后",hero.saveMemento());
    cout<<endl;

    hero.resumeMemento(ctk.GetMemento("战斗1后"));
    cout<<"-----恢复战斗1结果-----"<<endl;
    hero.showState();
    cout<<endl;

    hero.resumeMemento(ctk.GetMemento("战斗前"));
    cout<<"-----恢复战斗前-----"<<endl;
    hero.showState();
    cout<<endl;

    return 0;
}