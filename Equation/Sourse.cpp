#include<iostream>
#include<cmath>

class Equation
{
public:
	virtual void Solve() = 0;
};

class LinearEquation : public Equation
{
private :
	double a;
	double b;
public:
	LinearEquation() : a(0.0),b(0.0){}
	LinearEquation(double a,double b) : a(a),b(b){}

	void Solve() override
	{
		if (a == 0)
		{
			if (b == 0)
			{
				std::cout << "The equation has many solutions." << std::endl;
			}
			else
			{
				std::cout << "The equation has no solutions. " << std::endl;
			}
		}
		else
		{
			double x = -b / a;
			std::cout << "Solution of equation : x =  " << x << std::endl;
		}
	}
};
class QuadraticEquation : public Equation
{
private:
	double a;
	double b;
	double c;
public:
	QuadraticEquation() : a(0), b(0), c(0) {}
	QuadraticEquation(double a, double b, double c) : a(a),b(b),c(c){}

	void Solve()override
	{
		double discriminant = b * b - 4 * a * c;

		if (discriminant > 0)
		{
			double x1 = (-b + std:: sqrt(discriminant)) / (2 * a);
			double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
			std::cout << "Two solution : x1 = " << x1 << ", x2 = " << x2 << std::endl;
		}
		else if (discriminant == 0)
		{
			double x = -b / (2 * a);
			std::cout << "One solution : x = " << x << std::endl;
		}
		else
		{
			std::cout << "Equation has no valid solutions" << std::endl;
		}
	}
};

int main()
{
	Equation* equation1 = new LinearEquation(2.0, 3.0);
	Equation* equation2 = new QuadraticEquation(1.0, -3.0, 2.0);

	equation1->Solve();
	equation2->Solve();

	delete equation1;
	delete equation2;

	return 0;
}