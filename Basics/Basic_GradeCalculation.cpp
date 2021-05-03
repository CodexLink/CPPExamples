//First Activity Done in 10 Minutes, No Value Checkers Added by Janrey Licas

//using namespace std....
// We are polluting the name space here so we use individal components instead of using namespace std;
// TL;DR Use Individual Components not the Whole Std~! Don't do "using namespace std". You are wasting resources ...

//using std::cout;
//using std::cin;
//using std::endl;

// Kapag nasanay ka na you can also call those commands with :: as well. Such as from example
/*
Example:
When declared with using...
using std::cout -> you can call cout with just cout
without std::cout -> you have to do it like this std::cout (This one might be better, situational when calling different namespaces(set of functions, container, also because if you have same function names and different namespace, you can see what is different) )

For Example
PersonOne::FunctionalConvert
PersonTwo::FunctionalConvert

Same Function Pero Different Functionality defined from the namespace...
 */

#include <iostream>
// Declaring some constant variables using #define...
#define ITERATOR_MAX 5
#define PASSED_VALUE 70
int main()
{
	unsigned short AllIn_Result, Input_TestScore;
	for (unsigned short Iterator_TestScores = 1; Iterator_TestScores <= ITERATOR_MAX; Iterator_TestScores++) // Use size_t when iterating through array... But you also use it right now.
	{
		std::cout << "Please Input Test " << Iterator_TestScores << " Scores: ";
		std::cin >> Input_TestScore;
		AllIn_Result += Input_TestScore;
	}
	AllIn_Result /= ITERATOR_MAX;
	std::cout << "Final Score Percentage > " << AllIn_Result << "% " << ((AllIn_Result >= PASSED_VALUE) ? ("PASSED") : ("FAILED")) << std::endl;
	return 0; // EXIT_SUCESS For Win32API
}
