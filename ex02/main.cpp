#include "Base.hpp"

int main(void)
{
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
