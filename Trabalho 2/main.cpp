#include "Interface.hpp"
#include "Queue.hpp"

int main() {
	Queue<char*> q(100);
	Interface i(&q);
	i.run();
	return 0;
}
