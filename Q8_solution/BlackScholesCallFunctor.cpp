#include "BlackScholesCallFunctor.h"
#include "../Black_Scholes_Helpers/Black_Scholes_Helpers.h"

BlackScholesCallFunctor::BlackScholesCallFunctor(double T, double K, double S, double r)
	:T{ T }, K{ K }, S{ S }, r{ r } {}

double BlackScholesCallFunctor::operator()(double sigma) const
{
	return call_price(S, K, T, r, sigma);
}
