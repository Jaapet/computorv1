#include "Polynomial.hpp"
#include <map>

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Invalid number of arguments." << std::endl, 1);

	std::map<int, float>	values;
	std::string	buffV;
	std::string	buffP;
	char	status = 'v'; //value, power
	bool	after = false; //after equ
	int		maxDegree = 0;

	for (int i = 0; av[1][i]; i++)
	{
		if (av[1][i] == '=')
			after = true;

		if (status == 'v' && av[1][i] == '^')
			status = 'p';
		if (status == 'p' && av[1][i] == ' ')
		{
			//std::cout << buffV << ", " << buffP << std::endl;
			if (atof(buffP.c_str()) != atoi(buffP.c_str()) || atof(buffP.c_str()) < 0)
				return (std::cerr << "Invalid power format." << std::endl, 1);
			if (after == false)
				values[atoi(buffP.c_str())] = atof(buffV.c_str());
			else if (after == true)
			{
				if (values[atoi(buffP.c_str())])
					values[atoi(buffP.c_str())] -= atof(buffV.c_str());
				else
					values[atoi(buffP.c_str())] = atof(buffV.c_str());
			}
			if (atoi(buffP.c_str()) > maxDegree)
				maxDegree = atoi(buffP.c_str());

			buffV.clear();
			buffP.clear();
			status = 'v';
		}

		if (status == 'v' && (isdigit(av[1][i]) || av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '.'))
			buffV.push_back(av[1][i]);
		if (status == 'p' && (isdigit(av[1][i]) || av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '.'))
			buffP.push_back(av[1][i]);

	}
	if (atof(buffP.c_str()) != atoi(buffP.c_str()) || atof(buffP.c_str()) < 0)
		return (std::cerr << "Invalid power format." << std::endl, 1);
	if (after == true)
	{
		if (values[atoi(buffP.c_str())])
			values[atoi(buffP.c_str())] -= atof(buffV.c_str());
		else
			values[atoi(buffP.c_str())] = atof(buffV.c_str());
	}
	if (atoi(buffP.c_str()) > maxDegree)
		maxDegree = atoi(buffP.c_str());

	// std::cout << values[2] << ", " << values[1] << ", " << values[0] << ", " << maxDegree << std::endl;

	Polynomial *p = new Polynomial(av[1], values[2], values[1], values[0], maxDegree);
	p->solve();
}