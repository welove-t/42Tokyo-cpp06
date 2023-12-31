#include "Serialization.hpp"

int main(void)
{
	Data* data = new Data();

	data->s_data = "good data!";
	data->i_data = 42;

	std::cout << GREEN <<  "original\t:" <<  data << RESET << std::endl;
	uintptr_t	ptr = Serialization::serialize(data);
	std::cout << "serialization\t:" << ptr << std::endl;
	std::cout << GREEN "derialization\t:" << Serialization::deserialize(ptr) << RESET << std::endl;

	delete data;
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
