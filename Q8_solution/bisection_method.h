constexpr int max_iterations = 1000; 

template <typename T>
double bisection_method(double y_target, double left, double right, double epsilon, T functor)
{
	double evaluate_left = functor(left) - y_target;
	double evaluate_right = functor(right) - y_target;
	int iterations_counter = 0;
	do
	{
		double mid_point = (left + right) / 2;
		double evaluate_mid = functor(mid_point) - y_target;
		if (abs(evaluate_mid - y_target) < epsilon)
		{
			return mid_point;
		}
		if (evaluate_left < 0 == evaluate_mid < 0)
		{
			left = mid_point;
			evaluate_left = evaluate_mid;
		}
		else
		{
			right = mid_point;
			evaluate_right = evaluate_mid;
		}
		iterations_counter++;
	} while (iterations_counter < max_iterations);
	throw std::runtime_error("Max iterations exceeded.");
}