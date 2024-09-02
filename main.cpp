#include "Polynomial.hpp"
#include <map>

int main(int ac, char **av)
{
	std::vector<float>	values;
	std::string	tmp;
	bool	state = 1;
	int		count = 0;
	std::string	sec;
	if (ac != 2)
		return (std::cerr << "Invalid number of arguments." << std::endl, 1);
	for (int i = 0; av[1][i]; i++)
	{
		if (av[1][i] == '=')
		{
			int j = i;
			while (av[1][j])
			{
				if (isdigit(av[1][j]) || av[1][j] == '.' || av[1][j] == '-')
					sec.push_back(av[1][j]);
				else if (av[1][j] == '^' && av[1][j + 1])
				{
					std::string pow;
					pow.push_back(av[1][j+1]);
					switch (atoi(pow.c_str()))
					{
					case 0:
						values[0] -= atof(sec.c_str());
						break;
					case 1:
						values[1] -= atof(sec.c_str());
						break;
					case 2:
						values[2] -= atof(sec.c_str());
						break;
					
					default:
						break;
					}
					sec.clear();
					pow.clear();
					break ;
				}
				j++;
			}
			break ;
		}
		if (av[1][i] == '+' || av[1][i] == '-')
			state = 1;
		else if (av[1][i] == '*')
		{
			state = 0;
			values.push_back(atof(tmp.c_str()));
			tmp.clear();
		}
		if (state == 1 && (isdigit(av[1][i]) || av[1][i] == '.' || av[1][i] == '-'))
		{
			tmp.push_back(av[1][i]);
			count++;
		}
	}


	Polynomial *p = new Polynomial(av[1], values[2], values[1], values[0]);

	std::string deg;
	for (int i = 0; av[1][i]; i++)
	{
		if (av[1][i] == '^' && av[1][i + 1])
		{
			deg.push_back(av[1][i + 1]);
			if (atoi(deg.c_str()) > p->getDegree())
				p->setDegree(atoi(deg.c_str()));
			deg.clear();
		}
	}
	p->solve();
}