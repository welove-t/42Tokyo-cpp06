#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: " << argv[0] << " <literal>" << RESET << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q convert");
}
