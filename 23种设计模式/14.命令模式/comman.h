/*
场景：
我们要设计一个遥控器，可以通过按动上边的控制按钮控制卧室和厨房的灯，还能控制卧室中的音响的开关。
遥控器是我们的“动作的请求者”，而灯和音响就是我们的“动作的执行者”。
当我们按动遥控器上的某个开关后，遥控器就可以把相关的指令发送到我们的指定的家电上。
这之中遥控器和家电之间是解耦的，我们完全可以通过设置，添加、修改或删除其它的家电控制功能，而不需要修改遥控器的代码。
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Command
{
public:
virtual void execute() = 0;
};

class NoCommand : public Command
{
public:
void execute() {};
};

class Light
{
public:
    Light(string location);
void on();
void off();
private:
string m_sLocation;
};

class LightOffCommand : public Command
{
public:
    LightOffCommand(string location):m_Light(location) {}
void execute();
private:
    Light m_Light;
};

class LightOnCommand : public Command
{
public:
    LightOnCommand(string location):m_Light(location) {}
void execute();
private:
    Light m_Light;
};

class Stereo
{
public:
    Stereo(string location);
void on();
void off();
void setCD();
void setDVD();
void setRadio();
void setVolume(int volume);
private:
string m_sLocation;
};

class StereoOnWithCDCommand : public Command
{
public:
    StereoOnWithCDCommand(string location):m_Stereo(location) {}

void execute();
private:
    Stereo m_Stereo;
};

class StereoOffCommand : public Command
{
public:
    StereoOffCommand(string location):m_Stereo(location) {}

void execute();
private:
    Stereo m_Stereo;
};

class RemoteControl
{
public:
    RemoteControl();
    ~RemoteControl();
void setCommand(int slot, Command* pOnCommand, Command* pOffCommand);
void onButtonWasPushed(int slot);
void offButtonWasPushed(int slot);
private:
    vector<Command*> m_OnCommands;
    vector<Command*> m_OffCommands;
};

Light::Light(string location)
{
    m_sLocation = location;
}

void Light::on()
{
    printf("%s light is on\n",m_sLocation.c_str());
}

void Light::off()
{
    printf("%s light is off\n",m_sLocation.c_str());
}

void LightOffCommand::execute()
{
    m_Light.off();
}

void LightOnCommand::execute()
{
    m_Light.on();
}

Stereo::Stereo(string location)
{
    m_sLocation = location;
}

void Stereo::on()
{
    printf("%s stereo is on\n",m_sLocation.c_str());
}

void Stereo::off()
{
    printf("%s stereo is off\n",m_sLocation.c_str());
}

void Stereo::setCD()
{
    printf("%s stereo is set for CD input\n",m_sLocation.c_str());
}

void Stereo::setDVD()
{
    printf("%s stereo is set for DVD input\n",m_sLocation.c_str());
}

void Stereo::setRadio()
{
    printf("%s stereo is set for Radio\n",m_sLocation.c_str());
}

void Stereo::setVolume(int volume)
{
    printf("%s Stereo volume set to %d\n",m_sLocation.c_str(),volume);
}

void StereoOnWithCDCommand::execute()
{
    m_Stereo.on();
    m_Stereo.setCD();
    m_Stereo.setVolume(11);
}

void StereoOffCommand::execute()
{
    m_Stereo.off();
}

RemoteControl::RemoteControl()
{
for (int i = 0; i < 7; i++)
    {
        Command* noCommandOn = new NoCommand();
        m_OnCommands.push_back(noCommandOn);
        Command* noCommandOff = new NoCommand();
        m_OffCommands.push_back(noCommandOff);
    }
}

RemoteControl::~RemoteControl()
{
for (int i = 0; i < 7; i++)
    {
        delete m_OnCommands.at(i);
        delete m_OffCommands.at(i);
    }
    m_OnCommands.clear();
    m_OffCommands.clear();
}

void RemoteControl::setCommand(int slot, Command* pOnCommand, Command* pOffCommand)
{
    delete m_OnCommands.at(slot); 
    m_OnCommands.at(slot) = pOnCommand;
    delete m_OffCommands.at(slot);
    m_OffCommands.at(slot) = pOffCommand;
}

void RemoteControl::onButtonWasPushed(int slot)
{
    m_OnCommands.at(slot)->execute();
}

void RemoteControl::offButtonWasPushed(int slot)
{
    m_OffCommands.at(slot)->execute();
}
