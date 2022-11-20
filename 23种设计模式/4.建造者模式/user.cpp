#include "product.h"
#include "builder.h"
#include "director.h"
int main() {
    ComputerDirector* director = new ComputerDirector();
    ComputerBuilder* builder = new MacComputerBuilder("I5处理器", "三星125");
    director->makeComputer(builder);
    Computer* macComputer = builder->getComputer();
    cout << "mac computer : ";
    macComputer->show();

    ComputerBuilder* lenovoBuilder = new LenovoComputerBuilder("I7处理器", "海力士222");
    director->makeComputer(lenovoBuilder);
    Computer* lenovoComputer = lenovoBuilder->getComputer();
    cout << "lenovo computer";
    lenovoComputer->show();

}