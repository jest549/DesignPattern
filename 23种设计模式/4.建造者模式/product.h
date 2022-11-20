#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>
#include <string>
using namespace std;
class Computer {
private:
    string _cpu; // 必须
    string _ram; // 必须
    int _usbCount; // 可选
    string _keyboard; // 可选
    string _display; // 可选
public:
    Computer(string cpu, string ram) : _cpu(cpu), _ram(ram) { }
    
    void setUsbCount(int usbCount) {
        this->_usbCount = usbCount;
    }

    void setKeyboard(string keyboard) {
        this->_keyboard = keyboard;
    }

    void setDisplay(string display) {
        this->_display = display;
    }

    void show() {
        cout << "{\n" << "  cpu : " << _cpu << endl
             << "  ram : " << _ram << endl << "  keyboard : " << _keyboard
             << endl << "  display : " << _display << endl
             << "}\n"; 
    }
};
#endif