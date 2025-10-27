#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void	replaceString(std::ofstream &ofs, std::string fileContents, char *string1, char *string2)
{
	unsigned int	i = 0;
	std::string	s1 = string1;
	std::string	s2 = string2;
	while (i < fileContents.length())
	{
		if (fileContents.compare(i, s1.length(), s1) == 0)
		{
			fileContents.erase(i, s1.length());
			fileContents.insert(i, s2);
			std::cout << fileContents[i] << std::endl;
		}
		i++;
	}
	ofs << fileContents;
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	std::string	filename = av[1];
	std::string	fileContents;
	std::ifstream	ifs(filename.c_str());
	std::stringstream	buffer;
	if (ifs.fail())
	{
		std::cout << "Couldn't open file" << std::endl;
		return (1);
	}
	buffer << ifs.rdbuf();
	fileContents = buffer.str();
	ifs.close();
	filename.append(".replace");
	std::ofstream	ofs(filename.c_str());
	replaceString(ofs, fileContents, av[2], av[3]);
	ofs.close();
	return (0);
}
