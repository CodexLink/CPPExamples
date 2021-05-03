/*
    Template Introduction
    1. Function Template
    2. Class Template
*/
#include <iostream>

template <class T>

class A
{

private:
    T VarContainer = NULL;

public:
    A(T GivenData) : VarContainer(GivenData) {}

    inline T getDataType() const
    {
    //    std::cout << "The type of the variable is " << typeof(&VarContainer) << std::endl;
    }

    inline T getDataContainer() const
    {
        return VarContainer;
    }

};

int main()
{
    A<long long int> B(123123123123132);
    std::cout << B.getDataContainer();
    ;
}
