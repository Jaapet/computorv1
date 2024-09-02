#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Polynomial
{
	private:
		std::string	expression;
		float	a;
		float	b;
		float	c;
		float	delta;
		int		degree;
		
	public:
		Polynomial(std::string expression, float a, float b, float c, int maxP);
		~Polynomial();

		void	solve();
};

Polynomial::Polynomial(std::string expression, float a, float b, float c, int degree)
{
	this->expression = expression;
	this->a = a;
	this->b = b;
	this->c = c;
	this->degree = degree;
}

Polynomial::~Polynomial(){}

void	Polynomial::solve()
{
	std::cout << "Standard form : ";
	if (a != 0)
		std::cout << this->a << "x^2";
	if (b != 0)
	{
		if (b > 0 && a != 0)
			std::cout << "+";
		std::cout << this->b << "x";
	}
	if (c != 0)
	{
		if (c > 0)
			std::cout << "+";
		std::cout << this->c;
	}
	std::cout << " = 0" << std::endl;


	std::cout << "Degree : " << this->degree << std::endl;
	if (this->degree > 2 || this->degree <= 0)
	{
		std::cout << "Can't solve" << std::endl;
		return ;
	}

	if (this->degree == 1)
	{
		std::cout << "Solution : x = " << -1 * this->c / this->b << std::endl;
	}

	else
	{
		this->delta = this->b *this->b - 4 * this->a * this->c;
		if (this->delta < 0)
			std::cout << "Not solvable : negative discriminant" << std::endl;
		else if (this->delta == 0)
		{
			std::cout << "Solvable : null discriminant" << std::endl;
			std::cout << "Solution : x = " << -1 * this->b / (2 * this->a) << std::endl;
		}
		else
		{
			std::cout << "Solvable : positive discriminant" << std::endl;
			std::cout << "Solutions : x' = " << (-1 * this->b - sqrt(this->delta)) / (2 * this->a) << " / x'' = " << (-1 * this->b + sqrt(this->delta)) / (2 * this->a) << std::endl;
		}
	}
	
}
