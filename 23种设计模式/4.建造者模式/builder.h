#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <iostream>
#include <string>
#include "product.h"
using namespace std;
class ComputerBuilder {
public:
    virtual void setUsbCount() = 0;
    virtual void setKeyboard() = 0;
    virtual void setDisplay() = 0;

    virtual Computer* getComputer() = 0;

    virtual ~ComputerBuilder() { }
};
class MacComputerBuilder : public ComputerBuilder {
private:
    Computer* _computer;

public: 

    MacComputerBuilder(string cpu, string ram) {
        _computer = new Computer(cpu, ram);
    }

    ~MacComputerBuilder() override {
        delete _computer;
    }

    void setUsbCount() override {
        _computer->setUsbCount(2);
    }

    void setKeyboard() override {
        _computer->setKeyboard("苹果键盘");
    }

    void setDisplay() override {
        _computer->setDisplay("苹果显示器");
    }

    Computer* getComputer() override {
        return _computer;
    }


};

class LenovoComputerBuilder : public ComputerBuilder {
private: 
    Computer* _computer;

public:
    LenovoComputerBuilder(string cpu, string ram) {
        _computer = new Computer(cpu, ram);
    }

    ~LenovoComputerBuilder() override {
        delete _computer;
    }

    void setUsbCount() override {
        _computer->setUsbCount(4);
    }

    void setKeyboard() override {
        _computer->setKeyboard("联想键盘");
    }

    void setDisplay() override {
        _computer->setDisplay("联想显示器");
    }

    Computer* getComputer() override {
        return _computer;
    }
};
#endif