#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include <iostream>
#include <string>
#include "product.h"
#include "builder.h"
using namespace std;
class ComputerDirector {
public:
    void makeComputer(ComputerBuilder* builder) {
        builder->setUsbCount();
        builder->setDisplay();
        builder->setKeyboard();
    }
};
#endif