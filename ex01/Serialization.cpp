#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(Serialization const & src)
{ 
(void)src; 
}


Serialization & Serialization::operator=(Serialization const & rhs)
{ 
    (void)rhs;
    return *this;
}

Serialization::~Serialization() {}

unsigned long Serialization::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr); // Convert pointer to unsigned long
}

Data* Serialization::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw); // Convert unsigned long back to pointer
}
