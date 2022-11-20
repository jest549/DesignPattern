#include "factory.h"
int main()
{
    CarFactory *benzfac = new BenzFactory();
    CarFactory *bmwfac = new BmwFactory();
    CarFactory *hondafac = new HondaFactory();

    BridgeCar *C200L = benzfac->createBridgeCar();
    BridgeCar *_530Li = bmwfac->createBridgeCar();
    BridgeCar * accord = hondafac->createBridgeCar();





    delete accord;
    delete C200L;
    delete _530Li;



    delete benzfac;
    delete bmwfac;
    delete hondafac;

    return 0;
}