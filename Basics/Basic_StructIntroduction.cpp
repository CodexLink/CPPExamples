/*
 Data Struct Group 5, Third Activity Part 3 First Optimization / Creation
 Created On: 06/24/2019
 Initially Created by Kristian B. Selga and Rejay V. Mar, Finished by Janrey Licas
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_INFO 3
//#define MAX_PATH 260//, Uncomment this if your compiler doesn't what this is. Most compilers already knew what MAX_PATH is...

void ShowDataResult(unsigned short Index_StructArray);

struct StudentEssential_Info
{
    char Stdnt_FullName[MAX_PATH];
    char Stdnt_Address[MAX_PATH];
    char Stdnt_Program[MAX_PATH];
    unsigned long long int Stdnt_MobileNumber;
    unsigned long long int Stdnt_IDNumber;
};

struct StudentEssential_Info Student_PredefinedInfo[MAX_ARRAY_INFO];
    
int main()
{
    // Initialized to Zero because we dont some random numbers coming in...
    unsigned long long int Query_StdntNumber = 0;
    unsigned short Struct_ArrayIndexAccess = 0;

    // Fill Those Data to Struct... Before Actual Execution...
    std::cout << "Initializing Struct with Defined Data..." << std::endl;
    for (unsigned short StructIterator = 0; StructIterator < MAX_ARRAY_INFO; StructIterator++)
    {
        switch (StructIterator)
        {
        case 0:
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_FullName, "Janrey T. Licas");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Address, "Nueve De Pebrero St. Mandaluyong City");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Program, "BS Computer Engineering");
            Student_PredefinedInfo[StructIterator].Stdnt_MobileNumber = 9275340186;
            Student_PredefinedInfo[StructIterator].Stdnt_IDNumber = 1810386;
            break;
        case 1:
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_FullName, "Rejay V. Mar");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Address, "Novaliches Quezon City");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Program, "BS Information Technology");
            Student_PredefinedInfo[StructIterator].Stdnt_MobileNumber = 9185206783;
            Student_PredefinedInfo[StructIterator].Stdnt_IDNumber = 1810083;
            break;
        case 2:
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_FullName, "Kristian B. Selga");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Address, "Quezon City");
            strcpy(Student_PredefinedInfo[StructIterator].Stdnt_Program, "BS Science Major in Medical Technology");
            Student_PredefinedInfo[StructIterator].Stdnt_MobileNumber = 9565027056;
            Student_PredefinedInfo[StructIterator].Stdnt_IDNumber = 1810816;
            break;
        }
    }
    std::cout << "Done." << std::endl;

    // Endlessly Loop for Struct Query
    while (1)
    {
	bool isIDFound = false;
        std::cout << "Please enter a student number > ";
        std::cin >> Query_StdntNumber;
	
        std::cout << "Querying..." << std::endl;	
	
	/* 
	2nd Optimization, Scalability Approach, in the first optimization I did a statically approach by assume that there will be no other Student IDs that has to be added from the system.
	So in this one, we are going to assume that the array byte of the array will be dynamically memory allocated by using mem functions. So in this case we are going to do a dynamic search by not declaring any
	defined value of switches... 
	*/
	for (unsigned short IndexStruct = 0; IndexStruct < MAX_ARRAY_INFO; IndexStruct++)
	{
		if (Query_StdntNumber == Student_PredefinedInfo[IndexStruct].Stdnt_IDNumber)
		{
			ShowDataResult(IndexStruct);
			isIDFound = true;
		}
	}

	if (isIDFound)
	{
            std::cout << "Query Done..." << std::endl;
	}
	else
	{
	   std::cout << "Unknown Data... Please try again..." << std::endl;
            continue;	
	}

    }
}

void ShowDataResult(unsigned short Index_StructArray)
{
	// Seperate and Beautify this part because why not?
            std::cout << "=======================================================" << std::endl;
            std::cout << "STUDENT INFORMATION" << std::endl;
            std::cout << "=======================================================" << std::endl << std::endl;
            std::cout << "Student Full Name -> " << Student_PredefinedInfo[Index_StructArray].Stdnt_FullName << std::endl;
            std::cout << "Student ID Number -> " << Student_PredefinedInfo[Index_StructArray].Stdnt_IDNumber << std::endl;
            std::cout << "Student Address   -> " << Student_PredefinedInfo[Index_StructArray].Stdnt_Address << std::endl;
            std::cout << "Student Program   -> " << Student_PredefinedInfo[Index_StructArray].Stdnt_Program << std::endl;
            std::cout << "Student Mobile #  -> " << Student_PredefinedInfo[Index_StructArray].Stdnt_MobileNumber << std::endl;
            std::cout << std::endl << "=======================================================" << std::endl << std::endl;
}
