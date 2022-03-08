#include <iostream>

#include "../Q8_solution/bisection_method.h"
#include "../Q8_solution/BlackScholesCallFunctor.h"

int main()
{
    double T = 0.25;
    double K = 95;
    double r = 10;
    double S = 100;
    double price = 13.6953;
    std::cout << "The inplied volatility of a call option with Expiry: 0.25, Strike price: 95, initial price: 100, r:10% is: \n)";

    BlackScholesCallFunctor functor(T, K, S, r);
    std::cout << interval_bisection<BlackScholesCallFunctor>(price, 100, 10, 0.00000001, functor);
}


