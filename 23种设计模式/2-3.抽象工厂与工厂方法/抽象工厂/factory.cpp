#include "factory.h"
int main()
{
    CarFactory *benzfac = new BenzFactory();
    CarFactory *bmwfac = new BmwFactory();
    CarFactory *hondafac = new HondaFactory();

    BridgeCar *C200L = benzfac->createBridgeCar();
    BridgeCar *_530Li = bmwfac->createBridgeCar();
    BridgeCar * accord = hondafac->createBridgeCar();

    SUVCar *GLC = benzfac->createSUVCar();
    SUVCar *X5 = bmwfac->createSUVCar();
    SUVCar *URV = hondafac->createSUVCar();


    SportCar *AMG = benzfac->createSportCar();
    SportCar *M4= bmwfac->createSportCar();
    SportCar *Type_R = hondafac->createSportCar();



    delete accord;
    delete C200L;
    delete _530Li;
    delete GLC;
    delete X5;
    delete URV;
    delete AMG;
    delete M4;
    delete Type_R;


    delete benzfac;
    delete bmwfac;
    delete hondafac;

    return 0;
}