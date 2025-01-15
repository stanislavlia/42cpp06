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
		i = std::stoi(literal);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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
        int value = std::stoi(literal);
        to_print = std::to_string(value);
    }
    catch(const std::exception& e)
    {
        to_print = "nan";
    }
    std::cout << "int: " << to_print << std::endl;
    
};


void ScalarConverter::convert(std::string input)
{

};