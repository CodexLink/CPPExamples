#include <iostream>
#define START_CHAR_POINT 'A' // A is on Alphabet #1
#define MAXIMUM_CHAR_POINT 'J' // J is on Alphabet #10
#define MIN_LIMIT_NUM 1 // Minimum Size is 10
#define MAX_LIMIT_NUM 10 // Max Size is 10
#define RETURN_SUCCESS // Returns Success... Similarly on Win32API for C++.
#define RETURN_MINVAL_FAIL 1 // Returns that the execution failed because of value goes less than MIN_LIMIT_NUM.
#define RETURN_MAXVAL_FAIL 2 // Returns that the execution failed because of value goes more than MAX_LIMIT_NUM.
int main()
{
	unsigned char Alphabet_Lttr = START_CHAR_POINT;
	unsigned short Alphabet_Idx = 0;
	std::cout << "Input a size of a half pyramid > ";
	std::cin >> Alphabet_Idx;
	if (Alphabet_Idx > MAX_LIMIT_NUM)
	{
		std::cout << "Error, size entered is exceed from a value / size of 10. Terminating on Keyboard Press...";
		return RETURN_MAXVAL_FAIL;
	}
	else if (Alphabet_Idx <= MIN_LIMIT_NUM)
	{
		std::cout << "Error, size entered is invalid from a value / size of 1 to 10. Terminating on Keyboard Press...";
		return RETURN_MINVAL_FAIL;
	}
	else
	{
		for (unsigned short Size_Iteration = 0; Size_Iteration < Alphabet_Idx; Size_Iteration++)
		{
			for (unsigned short Letter_Iteration = 0; Letter_Iteration <= Size_Iteration; Letter_Iteration++)
			{	
				std::cout << Alphabet_Lttr;
			}
			Alphabet_Lttr++;
			std::cout << std::endl;
		}
	}
	return 0; // EXIT_SUCCESS
}