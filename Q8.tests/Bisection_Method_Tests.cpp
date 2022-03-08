#include <math.h>

#include "pch.h"
#include "../Q8_solution/bisection_method.h"

class IdentityFunctor {
private:
	int target = 1;
public:
	explicit IdentityFunctor(int target) : target{ target } {}
	

	double operator()(double sigma)const
	{
		return sigma-target;
	}
};

class CubeFunctor {
private:
	int target = 1;
public:
	explicit CubeFunctor(int target) : target{ target } {}
	

	double operator()(double sigma)const
	{
		return sigma*sigma*sigma - target;
	}
};

TEST(TestCaseName, Identity_equals_0) {
	IdentityFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<IdentityFunctor>(0., 1., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}

TEST(TestCaseName, Cube_equals_0) {
	CubeFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<CubeFunctor>(0., 1., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}

TEST(TestCaseName, Identity_equals_1) {
	IdentityFunctor functor(1);
	double epsilon = 0.000000001;
	double actual = interval_bisection<IdentityFunctor>(0., 2., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= 1+epsilon) && (actual >= 1-epsilon));
}

TEST(TestCaseName, Cube_equals_1) {
	CubeFunctor functor(1);
	double epsilon = 0.000000001;
	double actual = interval_bisection<CubeFunctor>(0., 2., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= 1+epsilon) && (actual >= 1-epsilon));
}

TEST(TestCaseName, Identity_equals_0_2) {
	IdentityFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<IdentityFunctor>(0., -0.12321321321, 1, epsilon, functor);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}

TEST(TestCaseName, Cube_equals_0_2) {
	CubeFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<CubeFunctor>(0., -0.12321321321, 1, epsilon, functor);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}

TEST(TestCaseName, Identity_equals_1_2) {
	IdentityFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<IdentityFunctor>(1, 2., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= 1 + epsilon) && (actual >= 1 - epsilon));
}

TEST(TestCaseName, Cube_equals_1_2) {
	CubeFunctor functor(0);
	double epsilon = 0.000000001;
	double actual = interval_bisection<CubeFunctor>(1, 2., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= 1 + epsilon) && (actual >= 1 - epsilon));
}