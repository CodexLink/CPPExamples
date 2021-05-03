/*
 Data Struct Group 5, Third Activity Part 1 First Optimization / Creation
 Created On: 06/23/2019, On Lab
 Initially Created and Finished by Janrey Licas
 */

#include <iostream>

#define MAX_PAYLOAD 5

unsigned short *MyFunction(unsigned short ArrayReference[MAX_PAYLOAD]); // Function Prototype. We declare this one as a pointer to return an address pointed from the array given.

int main()
{
	unsigned short ArrayPayload[MAX_PAYLOAD] = {100, 200, 300, 400, 500};
	std::cout << "Passing ArrayPayload to MyFunction with Arguments of Unsigned Short Values..." << std::endl;
	unsigned short *q = MyFunction(ArrayPayload); // Run the whole function here and call the variable for the result.
	std::cout << "Address of 5th Element is (ArrayReference[4]) > " << q << std::endl;
}

unsigned short *MyFunction(unsigned short ArrayReference[MAX_PAYLOAD])
{
	std::cout << std::endl << "Printing Addresses of Index Array Element from 1 to 5..." << std::endl << std::endl;
	for (unsigned short IndexIterator = 0; IndexIterator < MAX_PAYLOAD; IndexIterator++)
	{
		std::cout << "ArrayReference > Index Array @ " << IndexIterator << " with a Value of " << ArrayReference[IndexIterator] << " > ";
		std::cout << &ArrayReference[IndexIterator] << std::endl;
	}
	return &ArrayReference[MAX_PAYLOAD - 1];
}
