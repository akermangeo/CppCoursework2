class BlackScholesCallFunctor
{
private:
	double T;
	double K;
	double S;
	double r;
public:
	BlackScholesCallFunctor(double T, double K, double S, double r);
	double operator()(double sigma) const;
};