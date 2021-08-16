#include <iostream>
#include <string>

#define MAX_PAYLOADS 5
#define MAX_CLASSIFIERS 3

unsigned short PayloadClassifiers = 1;

char ArrayPayload_1[5] = {'a', 'b', 'c', 'd', 'e'};
int ArrayPayload_2[5] = {123, 341, 514, 876, 354};
double ArrayPayload_3[5] = {100.123, 200.543, 300.234, 765.321, 502.275};

int main(void)
{
    for (unsigned short PayloadCounter = 0; PayloadCounter < MAX_CLASSIFIERS; PayloadCounter++)
    {
        for (unsigned short IndexIteration = 0; IndexIteration < MAX_PAYLOADS; IndexIteration++)
        {
            switch (PayloadClassifiers)
            {
            case 1:
                std::cout << "The Address of Variable ArrayPayload_1 with Index of " << IndexIteration << " has an address of " << (void *)&ArrayPayload_1[IndexIteration] << std::endl;
                break;
            case 2:
                std::cout << "The Address of Variable ArrayPayload_2 with Index of " << IndexIteration << " has an address of " << (int *)&ArrayPayload_2[IndexIteration] << std::endl;
                break;
            case 3:
                std::cout << "The Address of Variable ArrayPayload_3 with Index of " << IndexIteration << " has an address of " << (double *)&ArrayPayload_3[IndexIteration] << std::endl;
                break;
            }
        }
        std::cout << std::endl;
        PayloadClassifiers++;
    }
}
