#pragma once

#include "IDependency.h"

class ClassWeWantToTest
{
private:
	std::shared_ptr<IDependency> sp_dependency;

public:
	explicit ClassWeWantToTest(std::shared_ptr<IDependency> dependency) :sp_dependency(dependency) {}
	
	int should_return_2() const 
	{
		return sp_dependency->should_return_2();
	}
};

