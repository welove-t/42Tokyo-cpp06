#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = checkLiteralType(literal);
	char c;
	switch (type)
	{
		case NO_TYPE:
			std::cout << "NO" << std::endl;
			break;
		case CHAR_TYPE:
		{
			c = literal[0];
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			break;
		}
		case INT_TYPE:
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
			break;
		}
		case FLOAT_TYPE:
			std::cout << "FLOAT_TYPE" << std::endl;
			break;
		case DOUBLE_TYPE:
			std::cout << "DOUBLE_TYPE" << std::endl;
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

void	ScalarConverter::printChar(char c)
{
	if (isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

}

void	ScalarConverter::printInt(int i)
{
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "int: impossible" << std::endl;
	else std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat(float f)
{
    if (ft_isnan(f))
		std::cout << "float: nanf" << std::endl;
    else if (ft_isinf(f))
		 std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
    else std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
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
