// #include "Base.hpp"
// #include <cstdlib>
// #include <ctime>
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"
// #include <iostream>

#include "CheckBaseClass.hpp"

Base * generate(void)
{
    srand(time(NULL));
    int random_number = rand() % 3;

    switch (random_number) {
        case 1:
            return new A();
        case 2:
            return new B();
        default:
            return new C();
    };
}

void identify_point(Base *p)
{
    if(dynamic_cast<A *>(p)){std::cout << "A" << std::endl;}
    else if(dynamic_cast<B *>(p)){std::cout << "B" << std::endl;}
    else if(dynamic_cast<C *>(p)){std::cout << "C" << std::endl;}
}

void identify_ref(Base& p)
{
    if(dynamic_cast<A *>(&p)){std::cout << "A" << std::endl;}
    else if(dynamic_cast<B *>(&p)){std::cout << "B" << std::endl;}
    else if(dynamic_cast<C *>(&p)){std::cout << "C" << std::endl;}
}