#include "Manager.h"

int main() {

	struct Manager manager;
	manager.run = Run;

	manager.run(manager);
	
	return 0;
}