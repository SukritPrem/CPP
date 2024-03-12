#include "CheckBaseClass.hpp"
#include <unistd.h> // For Unix-like systems

int main(void)
{
    A *testA = new A();
    B *testB = new B();
    C *testC = new C();

    identify_point(testA);
    identify_point(testB);
    identify_point(testC);

    for (int i = 0; i < 10; i++)
    {
        Base* test = generate();
        identify_ref(*test);
        delete test;
        sleep(1);
    }
    delete testA;
    delete testB;
    delete testC;

}
