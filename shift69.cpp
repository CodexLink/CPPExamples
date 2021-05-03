#include <iostream>
#include <string>
#include <cstdlib>

#define UL unsigned long
int main(void)
{
    std::string asd = "CodexLink";

    // Shifting in 69.

    // for (auto data : asd)
    // {
    //     // std::cout << (UL)data << std::endl;
    //     // // std::cout << (UL)(data << 13) << std::endl;

    //     // std::cout << (UL)(data << 13) << std::endl;
    //     // std::cout << ((char)"A" >> 13) << std::endl;

    //     ;

    // }

    std::cout << atoi("A" >> 13) << std::endl;

    // std::cout << (asd << 69) << std::endl;
    return 0;
}