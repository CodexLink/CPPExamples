//Second Activity - Second Optimization, --No Value Checkers Implemented, Created by Group 5, --Leader Janrey Licas
// Modified on: 6/21/2019

#include <iostream>

#define ITERATOR_MAX 5
#define PASSED_VALUE 70

// Define User-Defined Function so we can run this function on any place we like. (There is a rule about from bottom to top runtimes(?))

std::string ShowResults(unsigned short TestScore_Array[ITERATOR_MAX]);

// Main Application Start.

int main()
{
	unsigned short TestScores_Holder[ITERATOR_MAX] = {0};
	for (unsigned short Initial_Iteration = 0; Initial_Iteration < ITERATOR_MAX; Initial_Iteration++)
	{
		std::cout << "Please Input Test " << Initial_Iteration + 1 << " Scores: ";
		std::cin >> TestScores_Holder[Initial_Iteration];
	}
	std::cout << ", Computation Result > " << ShowResults(TestScores_Holder) << std::endl;
	
	std::cout << std::endl << "Function Execution is Finished, Return is always EXIT_SUCCESS (0)." << std::endl;
	
	return 0;
}

std::string ShowResults(unsigned short TestScore_Array[ITERATOR_MAX])
{
	unsigned short AllIn_Result; // we can use float here to display decimal numbers here.
	for (unsigned short ArrayIndexValue = 0; ArrayIndexValue < ITERATOR_MAX; ArrayIndexValue++)
	{
		AllIn_Result += TestScore_Array[ArrayIndexValue];
	}
	
	std::cout << std::endl << "Final Score Percentage > " << (AllIn_Result /= ITERATOR_MAX) << "%";
	
	// NOTE: NOT Unary-able because of return expression error. I, we, don't know the cause of it.
	if (AllIn_Result >= PASSED_VALUE)
	{
		return "PASSED";	
	} 
	else
	{
		return "FAILED";
	}
}
