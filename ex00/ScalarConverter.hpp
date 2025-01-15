#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <limits>

class  ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other); //copy constructor
        ScalarConverter &operator=(ScalarConverter const &other); //copy assignment
        ~ScalarConverter(); //destructor

        //helpers

        static void printChar(const std::string &literal);
        static void printInt(const std::string &literal);
        static void printFloat(const std::string &literal);
        static void printDouble(const std::string &literal);

    
    public:
        static void convert(std::string input);


};


#endif