#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = checkLiteralType(literal);
	switch (type)
	{
		case NO_TYPE:
			std::cout << "NO" << std::endl;
			break;
		case CHAR_TYPE:
			std::cout << "CHAR_TYPE" << std::endl;
			break;
		case INT_TYPE:
			std::cout << "INT_TYPE" << std::endl;
			break;
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

// bool	ScalarConverter::isFloat(const std::string& literal)
// {
// 	if (!(literal.back() == 'f'))
// 		return false;
// 	std::istringstream iss(literal);
// 	float f;

// 	iss >> f;

// 	// eofbitをチェックして文字列の終端に到達したか確認
// 	// failbitやbadbitをチェックして変換に失敗していないか確認
// 	return !(iss.fail() || !iss.eof());
// }

// bool	ScalarConverter::isDouble(const std::string& literal)
// {
// 	std::istringstream iss(literal);
// 	double d;
// 	iss >> d;

// 	// eofbitをチェックして文字列の終端に到達したか確認
// 	// failbitやbadbitをチェックして変換に失敗していないか確認
// 	return !(iss.fail() || !iss.eof());
// }

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
