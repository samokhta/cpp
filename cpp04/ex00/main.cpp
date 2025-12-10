#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();

	std::cout << "---------------------------------------------getType" << std::endl;
	std::cout << "meta type: " << meta->getType() << " " << std::endl;
	std::cout << "i type: " << i->getType() << " " << std::endl;
	std::cout << "j type: " << j->getType() << " " << std::endl;
	std::cout << "wMeta type: " << wMeta->getType() << " " << std::endl;
	std::cout << "wCat type: " << wCat->getType() << " " << std::endl;
	std::cout << "-------------------------------------------makeSound" << std::endl;
	std::cout << "meta sound: ";
	meta->makeSound();
	std::cout << "i sound: ";
	i->makeSound();
	std::cout << "j sound: ";
	j->makeSound();
	std::cout << "wMeta sound: ";
	wMeta->makeSound();
	std::cout << "wCat sound: ";
	wCat->makeSound();
	std::cout << "-----------------------------------------Destructors" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete wMeta;
	delete wCat;
	return (0);
}
