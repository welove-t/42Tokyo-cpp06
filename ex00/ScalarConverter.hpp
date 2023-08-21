#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

enum LiteralType
{
	NO_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
};
class ScalarConverter
{
	private:
		static bool	isValidDecimal(const std::string& literal, int end);
		// static bool	isDouble(const std::string& literal);
		// static bool	isFloat(const std::string& literal);
		static bool	isInt(const std::string& literal);
		static LiteralType checkLiteralType(const std::string& literal);
		static void	printChar(char c);
		// static void	printInt(const std::string& literal);
		// static void	printFloat(const std::string& literal);
		// static void	printDouble(const std::string& literal);
	public:
		static void	convert(const std::string& literal);

};

#endif

