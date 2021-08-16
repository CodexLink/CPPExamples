#include <iostream>

int main()
{
    int x = 25; // Initialize A Variable with A Value of 25
    int *p = &x; // Initialize A Pointer That Contains the Address of x.

    // * Displays x value which is 25.
    // * Displays Address of X which is literally an address of x.
    // * Displays p variable which contains the actual address.
    // * Dereferencing P will show up the result of 25 which is the value of x originally.
    // * Bonus, It Display an Address of an Dereferenced Variable, meaning 'What is the address of this dereeferenced operator?'
    std::cout << x << " " << &x << " " << p << " " << *p << " " << &*p << std::endl;
}