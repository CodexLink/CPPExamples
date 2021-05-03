#include <iostream>

class BaseClass
{
public:
    void show()
    {
        std::cout << "Base class show function called." << std::endl;
    }
    virtual void print()
    {
        std::cout << "Base class Print function called." << std::endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    void show()
    {
        std::cout << "Derived class class show function called." << std::endl;
    }

    void print()
    {
        std::cout << "Derived class Print function called." << std::endl;
    }
};


int main()
{
    BaseClass* bptr;
    DerivedClass obj;


    bptr = &obj;
    // Run Time Polymorphism
    bptr->print(); // Derived Called PrintFN Called.
    bptr->show(); // Derived Called ShowFN Called.

    return 0;
}