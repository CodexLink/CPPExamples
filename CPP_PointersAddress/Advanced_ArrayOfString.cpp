#include <iostream>


int main() {

    const char *arrOfData[] = { "asd", "asd" };


    for (auto &eachData : arrOfData) {
        std::cout << eachData << std::endl;
    }



    return 0;
}