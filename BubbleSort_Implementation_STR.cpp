/* Laboratory Activity 6, Bubble Sort on Strings, By Janrey Licas, CPE21FB1
DO NOT REDISTRIBUTE, IM WARNING YOU.
Level up your readibility if you have to.
*/
#include <iostream>
#define OPERATION_SUCCESS 0
#define OPERATION_FAILED -1
#define INIT_NULL 0
#define INITIAL_CHECK 0
#define STR_EQUAL 0
#define POS_OFFSET_BY_ONE 1
#define MAX_CONSTRAINT 5 // ALREADY DEFINED CONSTRAINT BASED ON QUESTION
#define SORT_TYPE "Bubble Sort"

void DisplayArray_SortProcess(std::string ArrayContainer[MAX_CONSTRAINT]);
void DisplayArray_BinarySearch(std::string ArrayContainer[MAX_CONSTRAINT], unsigned short LeftArrayIndex, unsigned short RightArrayIndex);
bool BinarySearch_Str(std::string ArrayContainer[MAX_CONSTRAINT], unsigned short LeftArrayIndex, unsigned short RightArrayIndex, std::string StrToSearch);

int main()
{
    std::string LN_Container[MAX_CONSTRAINT] = {"Licas", "Tuazon", "Diaz", "Rastica", "Padilla"}, LNStr_ToSearch; // Payload #1
    //std::string LN_Container[MAX_CONSTRAINT] = {"Regulation", "Moreno", "Mascarenas", "Chua", "Matienzo"}, LNStr_ToSearch; // Payload #2
    //std::string LN_Container[MAX_CONSTRAINT] = {"Banzuelo", "Perlado", "Diaz", "Embuido", "Portento"}, LNStr_ToSearch; //Payload #3
    //std::string LN_Container[MAX_CONSTRAINT] = {"Katou", "Sawamura", "Mizuhara", "Hyoudou", "Kasumigaoka"}, LNStr_ToSearch; // Payload #4, Saenai Heroine no Sodatekata Reference <3
    DisplayArray_SortProcess(LN_Container);                                                                                 // Displays Current Status of the Array.

    for (auto FirstElem = INIT_NULL; FirstElem < MAX_CONSTRAINT - POS_OFFSET_BY_ONE; FirstElem++)
    {
        for (auto SecondElem = INIT_NULL; SecondElem < MAX_CONSTRAINT - FirstElem - POS_OFFSET_BY_ONE; SecondElem++)
        {
            if (LN_Container[SecondElem].compare(LN_Container[SecondElem + POS_OFFSET_BY_ONE]) > STR_EQUAL)
            {
                swap(LN_Container[SecondElem], LN_Container[SecondElem + POS_OFFSET_BY_ONE]);
                DisplayArray_SortProcess(LN_Container);
            }
        }
    }
    std::cout << std::endl << "INPUT | Please input a student's last name to search |> ";
    std::cin >> LNStr_ToSearch, std::cout << std::endl;

    return BinarySearch_Str(LN_Container, INITIAL_CHECK, MAX_CONSTRAINT - POS_OFFSET_BY_ONE, LNStr_ToSearch);
}

void DisplayArray_SortProcess(std::string ArrayContainer[MAX_CONSTRAINT])
{
    static unsigned short DisplayCount;
    std::cout << SORT_TYPE << " | Pass Count " << DisplayCount << (!DisplayCount ? " Init. " : " ") << "|> ";
    for (auto DisplayArray = INIT_NULL; DisplayArray < MAX_CONSTRAINT; DisplayArray++)
    {
        std::cout << ArrayContainer[DisplayArray] << ((DisplayArray < MAX_CONSTRAINT - POS_OFFSET_BY_ONE) ? ", " : "");
    }
    std::cout << std::endl, DisplayCount++;
}

bool BinarySearch_Str(std::string ArrayContainer[MAX_CONSTRAINT], unsigned short LeftArrayIndex, unsigned short RightArrayIndex, std::string StrToSearch)
{
    bool isStringFound = false;
    unsigned short ArrElement_Mid = INIT_NULL;
    while (LeftArrayIndex <= RightArrayIndex)
    {
        ArrElement_Mid = (RightArrayIndex + LeftArrayIndex) / 2;
        DisplayArray_BinarySearch(ArrayContainer, LeftArrayIndex, RightArrayIndex);
        if (ArrayContainer[ArrElement_Mid].compare(StrToSearch) < STR_EQUAL)
        {
            LeftArrayIndex = ArrElement_Mid + POS_OFFSET_BY_ONE;
        }
        else if (ArrayContainer[ArrElement_Mid].compare(StrToSearch) > STR_EQUAL)
        {
            RightArrayIndex = ArrElement_Mid - POS_OFFSET_BY_ONE;
        }
        else if (ArrayContainer[ArrElement_Mid].compare(StrToSearch) == STR_EQUAL) // STR_EQUAL is 0, where .compare return value is 0 where 0 is both string is equal.
        {
            isStringFound = true;
            break;
        }
        else
        {
            isStringFound = false;
            break;
        }
    }
    if (isStringFound)
    {
        std::cout << std::endl
                  << "Student's Last Name String |> " << StrToSearch << " was found @ Index Position " << ArrElement_Mid << std::endl;
        return OPERATION_SUCCESS;
    }
    else
    {
        std::cout << std::endl
                  << "Student's Last Name String |> " << StrToSearch << " was unable to be found on any array index. Return Error " << OPERATION_FAILED << std::endl;
        return OPERATION_FAILED;
    }
}

void DisplayArray_BinarySearch(std::string ArrayContainer[MAX_CONSTRAINT], unsigned short LeftArrayIndex, unsigned short RightArrayIndex)
{
    static unsigned int BS_CounterPass;
    std::cout << "Binary Search Pass " << BS_CounterPass << " |> (" << LeftArrayIndex << " " << RightArrayIndex << ") |> ";
    for (auto ArrIterate = LeftArrayIndex; ArrIterate <= RightArrayIndex; ArrIterate++)
    {
        std::cout << ArrayContainer[ArrIterate] << ((ArrIterate < RightArrayIndex) ? ", " : " ");
    }
    std::cout << std::endl;
    BS_CounterPass++;
}
/* Laboratory Activity 6, Bubble Sort on Strings, By Janrey Licas, CPE21FB1
DO NOT REDISTRIBUTE, IM WARNING YOU.
Level up your readibility if you have to.
*/