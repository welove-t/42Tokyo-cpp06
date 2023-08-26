#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

struct Data
{
	std::string s_data;
	int			i_data;
};

class Serialization
{
	private:
		Serialization();
		~Serialization();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif

