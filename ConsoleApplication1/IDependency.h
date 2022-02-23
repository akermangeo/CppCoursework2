#pragma once
class IDependency
{
public:
	virtual int should_return_2() = 0;

	virtual ~IDependency() = default;
};

