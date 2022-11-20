#include "factory.h"
int main()
{
    CarFactory *fac = new CarFactory();


    BridgeCar *C200L = fac->createBridgeCar("Benz");
    BridgeCar *_530Li = fac->createBridgeCar("Bmw");
    BridgeCar * accord = fac->createBridgeCar("Honda");





    delete accord;
    delete C200L;
    delete _530Li;

    return 0;
}