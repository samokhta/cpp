#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wMeta->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wMeta->makeSound();
	wCat->makeSound();
	std::cout << "----------------------------------------------------" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete wMeta;
	delete wCat;
	return (0);
}