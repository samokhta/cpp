#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << std::endl << "----------Initial Tests----------" << std::endl << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << std::endl << "----------Array Construction----------" << std::endl << std::endl;

	int	nbr = 4;

	Animal* Animals[nbr];

	for (int i = 0; i != nbr; i++)
	{
		if ((i % 2) == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	std::cout << std::endl << "----------Dog Tests----------" << std::endl << std::endl;

	std::cout << "	Constructing newDog" << std::endl;
	Dog* newDog = new Dog();
	std::cout << "newDog idea 0: " << newDog->getIdea(0) << std::endl;
	std::cout << "newDog idea 3: " << newDog->getIdea(3) << std::endl << std::endl;

	std::cout << "	Constructing copyDog and copy assigning it" << std::endl;
	Dog* copyDog = new Dog();
	*copyDog = *newDog;
	std::cout << "copyDog idea 0: " << copyDog->getIdea(0) << std::endl;
	std::cout << "copyDog idea 3: " << copyDog->getIdea(3) << std::endl << std::endl;
	
	std::cout << "	giving newDog and copyDog different ideas" << std::endl;
	newDog->setIdea(3, "eat a bone");
	copyDog->setIdea(0, "zzzzz");
	std::cout << "newDog idea 0: " << newDog->getIdea(0) << std::endl;
	std::cout << "newDog idea 3: " << newDog->getIdea(3) << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getIdea(0) << std::endl;
	std::cout << "copyDog idea 3: " << copyDog->getIdea(3) << std::endl << std::endl;

	std::cout << std::endl << "----------Cat Tests----------" << std::endl << std::endl;

	std::cout << "	Constructing newCat" << std::endl;
	Cat* newCat = new Cat();
	std::cout << std::endl << "	giving newCat an idea" << std::endl;
	newCat->setIdea(42, "chase mice");
	std::cout << "newCat idea 42: " << newCat->getIdea(42) << std::endl << std::endl;

	std::cout << "	Constructing newCat with copy constructor" << std::endl;
	Cat* copyCat = new Cat(*newCat);
	std::cout << "copyCat idea 42: " << copyCat->getIdea(42) << std::endl << std::endl;

	std::cout << "	comparing newCat and copyCat ideas" << std::endl;
	std::cout << "newCat idea 42: " << newCat->getIdea(42) << std::endl;
	std::cout << "copyCat idea 42: " << copyCat->getIdea(42) << std::endl << std::endl;

	std::cout << "	giving copyCat a different idea" << std::endl << std::endl;
	copyCat->setIdea(42, "hiss at owner");
	std::cout << "copyCat idea 42: " << copyCat->getIdea(42) << std::endl << std::endl;

	std::cout << "	comparing newCat and copyCat ideas again" << std::endl;
	std::cout << "newCat idea 42: " << newCat->getIdea(42) << std::endl;
	std::cout << "copyCat idea 42: " << copyCat->getIdea(42) << std::endl << std::endl;


	std::cout << std::endl << "----------Array/Object Destruction----------" << std::endl << std::endl;
	for (int i = 0; i < nbr; ++i)
		delete Animals[i];

	delete newDog;
	delete copyDog;

	delete newCat;
	delete copyCat;

	return 0;
}
