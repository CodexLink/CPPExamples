// Credits to Paul Programming, https://www.youtube.com/watch?v=ZMDYsr9scGo.
#include <iostream>
#include <cstdlib>

int main() {
    int box = 5;
    int *ptr = &box;
    int **dptr = &ptr;

    std::cout << "box holds : " << box << std::endl;
    std::cout << "box lives at " << &box << std::endl;
    std::cout << "ptr points to address: " << ptr << std::endl;
    std::cout << "The thing that ptr points to has the value: " << *ptr << std::endl;
    std::cout << "ptr lives at " << &ptr << std::endl;
    std::cout << "dptr points to: " << dptr << std::endl;
    std::cout << "The thing that dptr points to has the value: " << *dptr << std::endl;
    std::cout << "The ptr that dptr points to, points to an int with the value: " << **dptr << std::endl;
    std::cout << "dptr lives at: " << *dptr << std::endl << std::endl;

    std::cout << "Pointer Overview." << std::endl;
    std::cout << "Thing:\t\tdptr\t\tptr\t\tbox" << std::endl;
    std::cout << "Value: \t" << "\t" << dptr << "\t" << ptr << "\t" << box << std::endl;
    std::cout << "Address: " << "\t" << &dptr << "\t" << &ptr << "\t" << &box << std::endl;
    std::cout << "Dereferenced: " << "\t" << *dptr << "\t" << *ptr << "\t\t" << "N/A" << std::endl;
    std::cout << "Another: " << "\t" << **dptr << std::endl;

    std::cout << "Experimentation" << std::endl;

    std::cout << "Direct Derefenrence by Referencing Variable with &?" << **&ptr << "\t" << *&ptr << std::endl;

    int &circle = *ptr; // If you want to use & in variable. You need to refer a variable as a pointer.
    std::cout << "Reverse | Automatic Dereference from Pointed Address? " << circle << std::endl;

    int *&triangle = ptr; // You cannot do this as if *& + * (implicit) = &. Literally returns address.
    // Referring another * to the variable during print is possible.

    std::cout << "Reverse | Automatic Dereference without Prefix? " << triangle << std::endl;
    return 0;
}