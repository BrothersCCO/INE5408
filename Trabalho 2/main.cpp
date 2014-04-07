#include "Interface.hpp"
#include "Queue.hpp"

#define MAXFILA 10

int main() {
	Queue<DataItem> q(MAXFILA);
	Interface i(&q);
	i.run();
	return 0;
}
