#include "proxy.h"
int main() {
    Person* tom = new Tom;
    Person* proxy = new Proxy(tom);
    proxy->rentHouse();
    return 0;
}