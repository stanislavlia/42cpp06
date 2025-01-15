#include "Serialization.hpp"

int main()
{
    Data *data = new Data;
    data->age = 19;
    data->height = 187;
    data->usd_amount=3232332;
    data->string="Hello world!";

    unsigned long data_serialized = Serialization::serialize(data);


    Data *unserialized = Serialization::deserialize(data_serialized);


    std::cout << "Deserialized:" << std::endl;
    std::cout << "Age: " <<unserialized->age << std::endl;
    std::cout << "height: " <<unserialized->height << std::endl;
    std::cout << "usd: " <<unserialized->usd_amount << std::endl;
    std::cout << "string: " <<unserialized->string << std::endl;

};