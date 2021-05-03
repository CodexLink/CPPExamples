/*
 Data Struct Group 5, Third Activity Part 2 First Optimization / Creation
 Created On: 06/23/2019
 Initially Created and Finished by Janrey Licas, Reviewed and Semi-Initialized by Kristian B. Selga and Rejay V. Mar
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_PROCESS_ITERATION 3

int main()
{
	std::string Container;
	char CharacterTarget;
	unsigned short IdenticalChar = 0;
	bool RunOnce = true, StringEndBuffer = false;

	std::cout << "Please enter a string (without space) > ";
	std::cin >> Container;
	std::cout << "Please enter a letter to target from string > ";
	std::cin >> CharacterTarget;

	// We display the user inputted again for clarification.
	std::cout << std::endl << "========================================" << std::endl;
	std::cout << "String Given: " << Container << " | String Length: " << Container.length() << std::endl;
	std::cout << "Target Character: " << CharacterTarget << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl << "Processing Data..." << std::endl;

	/* 
	Assume that this is a pratical and good approach but it's a difficult one to do because there is 
	one uneven case function. For example, case 1 differs on how it works from other case. In the process of creating this approach it's mind numbing.
	*/
	for (unsigned short ProcessIteration = 1; ProcessIteration <= MAX_PROCESS_ITERATION; ProcessIteration++)
	{
		for (unsigned short StringIteration = 0; StringIteration < Container.size(); StringIteration++)
		{
			// Checks if we are in the end of the string... This is useful from else statement from the if statement below.
			(StringIteration == Container.size() - 1) ? StringEndBuffer = true : StringEndBuffer = false;
			// Some approach, ever since we are gonna have some redundance from looping all over for each objective given. We used switch.
			if (Container[StringIteration] == CharacterTarget)
			{
				switch (ProcessIteration)
				{
				case 1:
					if (StringEndBuffer)
					{
						std::cout << "[GetOccuredCharacterAppears] -> Letter / Character '" << CharacterTarget << "' appeared " << IdenticalChar + 1 << " time(s).";
					}
					else
					{
						IdenticalChar++;
					}
					break;
				case 2:
					if (RunOnce)
					{
						std::cout << std::endl << "[GetCharacterIndiceLocation] -> Letter / Character '" << CharacterTarget << "' is located at indice/s > ";
						RunOnce = false;
					}
					std::cout << StringIteration << " ";
					break;
				case 3:
					if (RunOnce)
					{
						std::cout << std::endl << "[GetAddressFromString] -> Letter / Character '" << CharacterTarget << "' from string has address/es -> ";
						RunOnce = false;
					}
					std::cout << (std::string *)&Container[StringIteration] << " "; // We typecast this part because it returns an actual value rather than addresses with string because that's the main datatype of the base variable. 
					break;
				default:
					std::cout << "Invalid Parameter, Terminating..." << std::endl;
					break;
					return 0; // EXIT_SUCCESS
				}
			}
			else
			{
			/* 
				This is a workaround from a problem that I think for 2 hours to solve...
				This is a conflict from Switch Case 1, everything else is working properly.
			*/
				if (StringEndBuffer && ProcessIteration == 1) // We check if its really one or else it will run from any signed (positive) numbers...
				{
					std::cout << "[GetOccuredCharacterAppears] -> Letter / Character '" << CharacterTarget << "' appeared " << IdenticalChar << " time(s).";
				}
			}
		}
		RunOnce = true; // For each 2nd layer for loop function we revert our RunOnces for Other Case.
	}
	std::cout << std::endl << "Program Execution Done..." << std::endl;
}
