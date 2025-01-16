#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


int generateRandomInt(int min, int max)
{
    // Ensure min <= max
    if (min > max) {
        std::swap(min, max);
    }
    // Generate a random integer in the range [min, max]
    return min + (std::rand() % (max - min + 1));
}


Base* generate(void)
{
    int decision = generateRandomInt(0, 2);

    switch (decision)
    {
    case 0:
        std::cout << "Generated A" << std::endl;
        return new A;
    
    case 1:
        std::cout << "Generated B" << std::endl;
        return new B;
    case 2:
        std::cout << "Generated C" << std::endl;
        return new C;
    default:
        std::cout << "Generated A" << std::endl;
        return new A;
    }
};


void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "This is A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "This is B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "This is C" << std::endl;
        return;
    }

    std::cout << "This is Unknown class" << std::endl;
}


void identify(Base &p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "This is A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "This is B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "This is C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }

    std::cout << "This is Unknown class" << std::endl;

};


int main() {
    // Set seed
    std::srand(std::time(0));

    std::cout << "===========By pointer:================" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base* obj = generate(); 
        identify(obj);         
        delete obj;             
    }

    std::cout << "=========By reference:=====================" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base* obj = generate(); 
        identify(*obj);         
        delete obj;             
    }

    return 0;
}
