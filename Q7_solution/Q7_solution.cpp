#include <iostream>

#include "../Black_Scholes_Helpers/Black_Scholes_Helpers.h"

int main()
{
    using namespace std;

    double t = 0.25;
    double K = 95;
    double S = 100;
    double sigma = 50;
    double r = 10;

    double call = call_price(S, K, t, r, sigma);

    cout << "Call Price: " << call << " USD";

    return EXIT_SUCCESS;
}