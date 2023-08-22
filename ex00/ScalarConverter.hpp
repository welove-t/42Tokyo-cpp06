#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

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
		static LiteralType checkLiteralType(const std::string& literal);
		static bool	isValidDecimal(const std::string& literal, int end);
		static bool	isInt(const std::string& literal);
		static void	processChar(const std::string& literal);
		static void	processInt(const std::string& literal);
		static void	processFloat(const std::string& literal);
		static void	processDouble(const std::string& literal);
		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f);
		static void	printDouble(double d);

		static bool ft_isnan(float x);
		static bool ft_isnan(double x);
		static bool ft_isinf(float x);
		static bool ft_isinf(double x);
	public:
		static void	convert(const std::string& literal);

};

#endif

