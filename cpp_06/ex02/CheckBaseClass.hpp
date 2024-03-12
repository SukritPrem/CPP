

#ifndef CHECKBASECLASS_H
#define CHECKBASECLASS_H
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Function declarations
Base* generate(void);
void identify_point(Base* p);
void identify_ref(Base& p);

#endif