#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
};

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
};


ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other) {}
    return (*this);
}


void ScalarConverter::printChar(const std::string &literal)
{
    int i = 0;
    std::string to_print;

	try
	{
		i = std::atoi(literal.c_str());
	}
	catch(...)
	{
		to_print = "nan";
	}
	char c = static_cast<char>(i);
	if (std::isprint(c))
		to_print = (std::string("'") + c + std::string("'"));
	else
		to_print = "Non-displayable";

    std::cout << "char: " << to_print << std::endl;
};


void ScalarConverter::printInt(const std::string &literal)
{
    std::string to_print;

    try
    {
        int value = std::atoi(literal.c_str());
        std::ostringstream oss;
        oss << value;
        to_print = oss.str();
    }
    catch(...)
    {
        to_print = "nan";
    }
    std::cout << "int: " << to_print << std::endl;
    
};

void ScalarConverter::printFloat(const std::string &literal)
{
    std::string to_print;

    try
    {
        float value = std::strtof(literal.c_str(), NULL);
        std::ostringstream oss;
        oss << value << "f";
        to_print = oss.str();
    }
    catch(...)
    {
        to_print = "nan";
    }
    std::cout << "float: " << to_print << std::endl;
    
};


void ScalarConverter::printDouble(const std::string &literal)
{
    std::string to_print;

    try
    {
        double value = std::strtod(literal.c_str(), NULL);
        std::ostringstream oss;
        oss << value;
        to_print = oss.str();
    }
    catch(...)
    {
        to_print = "nan";
    }
    std::cout << "double: " << to_print << std::endl;
    
};


void ScalarConverter::convert(std::string input)
{
    try
    {
        char *end;
        std::strtof(input.c_str(), &end);
        size_t pos = end - input.c_str();
        if ((pos != input.length() && pos != input.length() - 1) //there is invalid trail in input 
			|| (pos == input.length() - 1
			&& input[pos] != 'f'
			&& input[pos] != 'F')) //there is number followed by neither f or F - invalid
            return (std::cout << "This is not a valid input" << std::endl, void());
    }
    catch (...) 
    {
        return (std::cout << "This is not a valid input" << std::endl, void());
    }

    if (input.compare("nan") == 0 || input.compare("nanf") == 0
		|| input.compare("inf") == 0 || input.compare("inff") == 0
		|| input.compare("+inf") == 0 || input.compare("+inff") == 0
		|| input.compare("-inf") == 0 || input.compare("-inff") == 0) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input << std::endl;
			return;
	}

    printChar(input);
    printInt(input);
    printFloat(input);
    printDouble(input);

};