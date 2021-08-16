/*
    Virtual Function Application Intro
    Description |>
*/


#include <iostream>

//Base Class
class Animal
{
public:
    virtual void eat()
    {
        std::cout << "Eating Generic Food." << std::endl;
    }
};
// Derived Class #1
class Cat : public Animal
{
public:
    void eat()
    {
        std::cout << "Eating Cat Food." << std::endl;
    }
};

// Derived Class #2
class Dog : public Animal
{
public:
    void eat()
    {
        std::cout << "Eating Dog Food." << std::endl;
    }
};

void RunFunction(Animal *PassedClassPtr)
{
    PassedClassPtr->eat();
}

int main()
{
    Animal* Base;
    Animal bBasic;
    Cat cCat;
    Dog dDog;

    Base = &cCat;
    RunFunction(Base);

    delete &cCat;


    Base = &dDog;

    RunFunction(Base);

    delete &dDog;

    Base = &bBasic;
    RunFunction(Base);
    return 0;
}