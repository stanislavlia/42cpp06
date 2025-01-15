#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>
#include <iostream>

struct Data {
    std::string string;
    int age;
    int usd_amount;
    float height;
};

class Serialization {
    private:
        Serialization();
        Serialization(Serialization const & src);
        Serialization & operator=(Serialization const & rhs);
        ~Serialization();
    public:
        static unsigned long serialize(Data* ptr); 
        static Data* deserialize(unsigned long raw);
};

#endif
