#include "Interface.hpp"
#include "Queue.hpp"

int main() {
	Queue<DataItem> q(100);
	Interface i(&q);
	i.run();
	return 0;
}
