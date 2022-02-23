#pragma once
#include <iostream>
#include "IDependency.h"

class Dependency final:
    public IDependency
{
    public:
        int should_return_2() override
        {
            std::cout << "Do_something method has been overriden in the base class";
            return 5; //Doesn't work
        }
        ~Dependency() override = default;
};

