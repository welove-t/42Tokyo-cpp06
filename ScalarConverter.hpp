#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		~ScalarConverter();

		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
};

#endif

