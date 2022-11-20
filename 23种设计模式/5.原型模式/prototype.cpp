#include "prototype.h"
int main() 
{
    Prototype* conProA = new ConcretePrototype(10);
    Prototype* conProB = conProA->clone();

    delete conProA;
    conProA = nullptr;

    delete conProB;
    conProB = nullptr;
}