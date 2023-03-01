#include "observe.h"
int main() {
	Me me;
	ObserverInterface* wife = new Wife;
	ObserverInterface* daughter = new Daughter;
	//订阅消息
	me.add(wife);
	me.add(daughter);

	//发通知
    std::cout << "爸爸回来了!" << std::endl;
	me.notify();

	delete wife;
	delete daughter;
}
