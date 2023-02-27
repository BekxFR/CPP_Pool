#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

Animal *groupe[20];

for(int i = 0; i < 10 ; i++)
{
	groupe[i] = new Dog();
}
for(int i = 10; i < 20 ; i++)
{
	groupe[i] = new Cat();
}

for(int i = 0; i < 20 ; i++)
{
	groupe[i]->makeSound();
}

for(int i = 0; i < 20 ; i++)
{
	delete groupe[i];
}

delete j;//should not create a leak
delete i;

std::cout << "#################################################" << std::endl;

Cat test;
test.printIdea(0);
test.setIdea("Mouaf Ouawwwwww I dont remember if i'am a cat or a dog !", 0);
test.makeSound();
test.printIdea(0);
Cat test2;
test2 = test;
test2.makeSound();
test2.printIdea(0);
test2.setIdea("Today i'aammm cat, yesterday i'was ...dog, tomorroaawww i will be?", 0);
test2.printIdea(0);
test.printIdea(0);
Cat Z(test);
Z.printIdea(0);

std::cout << "#################################################" << std::endl;

Animal *test1 = new Cat;
test1->makeSound();

delete test1;

std::cout << "#################################################" << std::endl;

Animal atest("Unicorn");
atest.makeSound();

return 0;
}
