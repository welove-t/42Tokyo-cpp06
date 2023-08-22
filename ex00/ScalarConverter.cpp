#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = checkLiteralType(literal);
	switch (type)
	{
		case NO_TYPE:
			std::cout << RED << "Bad Type !" << RESET << std::endl;
			break;
		case CHAR_TYPE:
			processChar(literal);
			break;
		case INT_TYPE:
			processInt(literal);
			break;
		case FLOAT_TYPE:
			processFloat(literal);
			break;
		case DOUBLE_TYPE:
			processDouble(literal);
			break;
		default:
			break;
	}
}

bool	ScalarConverter::isValidDecimal(const std::string& literal, int end)
{
	size_t dotCount = 0;
	size_t dotPosition = 0;

	size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	for (size_t i = start; i < literal.length() - end; ++i)
	{
		if (literal[i] == '.')
		{
			dotCount++;
			dotPosition = i;
		}
		else if (!isdigit(literal[i]))
			return false;
	}
	if (dotCount != 1)
		return false;
	if (dotCount == 1 && (dotPosition == 0 || dotPosition == literal.length() - 1))
		return false;
	return true;
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

LiteralType ScalarConverter::checkLiteralType(const std::string& literal)
{
	if (literal.empty())
		return NO_TYPE;
	if (literal.length() == 1 && std::isalpha(literal[0]))
		return CHAR_TYPE;
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return FLOAT_TYPE;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return DOUBLE_TYPE;
	if (isInt(literal))
		return INT_TYPE;
	if (literal.back() == 'f' && isValidDecimal(literal, 1))
		return FLOAT_TYPE;
	if (isValidDecimal(literal, 0))
		return DOUBLE_TYPE;
	return NO_TYPE;
}

void	ScalarConverter::processChar(const std::string& literal)
{
	char c = literal[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void	ScalarConverter::processInt(const std::string& literal)
{
	try
	{
		int i = std::stoi(literal);
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "The number is out of range for int." << RESET <<  std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << RED << "Invalid integer input." << RESET << std::endl;
	}
}

void	ScalarConverter::processFloat(const std::string& literal)
{
	try
	{
		float f = std::stof(literal);
		if (ft_isnan(f))
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<char>(f));
		if (ft_isnan(f) || (f < INT_MIN || INT_MAX < f))
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "The number is out of range for float." << RESET <<  std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << RED << "Invalid float input." << RESET << std::endl;
	}
}

void	ScalarConverter::processDouble(const std::string& literal)
{
	try
	{
		double d = std::stod(literal);
		if (ft_isnan(d))
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<char>(d));
		if (ft_isnan(d) || (d < INT_MIN || INT_MAX < d))
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble((d));
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "The number is out of range for double." << RESET <<  std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << RED << "Invalid double input." << RESET << std::endl;
	}
}

void	ScalarConverter::printChar(char c)
{
	if (isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat(float f)
{
	if (ft_isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (ft_isinf(f))
		 std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	ScalarConverter::printDouble(double d)
{
	if (ft_isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (ft_isinf(d))
		std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::ft_isnan(float x)
{
	return x != x;
}

bool ScalarConverter::ft_isnan(double x)
{
	return x != x;
}

bool ScalarConverter::ft_isinf(float x)
{
	return !ft_isnan(x) && ft_isnan(x - x);
}

bool ScalarConverter::ft_isinf(double x)
{
	return !ft_isnan(x) && ft_isnan(x - x);
}
