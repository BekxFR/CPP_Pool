#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	k->makeSound();
	meta2->makeSound();
	WrongCat wcat;
	wcat.makeSound();

	std::cout << "#########################################" << std::endl;

	delete meta;
	delete meta2;
	delete i;
	delete j;
	delete k;

	Animal anim1;
	Dog dog1;
	Cat cat1;
	Cat cat2;
	anim1 = dog1;
	// cat1 = dog1;
	cat1 = cat2;
	std::cout << anim1.getType() << " " << std::endl;
	std::cout << dog1.getType() << " " << std::endl;
	std::cout << cat1.getType() << " " << std::endl;
	std::cout << cat2.getType() << " " << std::endl;
	anim1.makeSound();
	dog1.makeSound();
	cat1.makeSound();
	cat2.makeSound();

	return 0;
}