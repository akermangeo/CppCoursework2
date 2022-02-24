// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ClassWeWantToTest.h"
#include "Dependency.h"

int main()
{
    std::shared_ptr<IDependency> sp_dependency = std::make_unique<Dependency>();
    ClassWeWantToTest class_to_test(sp_dependency);
    std::cout << class_to_test.should_return_2();
}

