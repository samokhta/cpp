#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << "----------" << std::endl;

	int	nbr = 4;

	Animal* Animals[nbr];

	for (int i = 0; i != nbr; i++)
	{
		if ((i % 2) == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	// Example: Accessing Dog/Cat member functions via dynamic_cast
	for (int i = 0; i < nbr; ++i)
	{
		if (Dog* dog = dynamic_cast<Dog*>(Animals[i]))
			dog->setIdea(3, "play with ball"); // Replace with actual Dog member function
		else if (Cat* cat = dynamic_cast<Cat*>(Animals[i]))
			cat->setIdea(8, "take a nap"); // Replace with actual Cat member function
	}

	// Don't forget to delete allocated memory
	for (int i = 0; i < nbr; ++i)
		delete Animals[i];
}