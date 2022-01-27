#include <iostream>


class Animal
{
    std::string greetings = "Empty";
    std::string childClass = "Empty";
    public:

        Animal(std::string i_greet, std::string i_child) : greetings(i_greet), childClass(i_child) {}

        virtual void voice(Animal* x) {};

        void meeting(Animal* a, Animal* b)
        {
            a->voice(b);
        }

        std::string getChildClass(Animal* x) {return childClass;}
};

class Dog : public Animal
{
    
    public:
        Dog() : Animal("Bark", "Dog") {}
    
        virtual void voice(Animal* b)
        {
            if (b->getChildClass(this) == "Dog")
                std::cout << "Woof-Woof\n";
            else 
                std::cout << "Bark Meow\n";
        }

};

class Cat : public Animal
{

    public:
        Cat() : Animal("Meow", "Cat") {}
        
        virtual void voice(Animal* b)
        {
            if (b->getChildClass(this) == "Cat")
                std::cout << "Purr Purr\n";
            else 
                std::cout << "Meow Bark\n";
        }

};


int main()
{
    Animal* a = new Dog();
    Animal* b = new Cat();
    Animal* c = new Dog();
    Animal* d = new Cat();
    
    a->meeting(a, c);
    a->meeting(a, b);
    a->meeting(b, c);
    a->meeting(b, d);
}
