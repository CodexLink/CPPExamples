/* Laboratory Activity 6, Merge Sort on Strings, By Janrey Licas, CPE21FB1
DO NOT REDISTRIBUTE, IM WARNING YOU.
Level up your readibility if you have to.
*/
#include <iostream>
#define OPERATION_SUCCESS 0
#define OPERATION_FAILED -1
#define INIT_NULL 0
#define INITIAL_INDEX 0
#define STR_EQUAL 0
#define POS_OFFSET_BY_ONE 1
#define SORT_TYPE "Merge Sort"

// NOTE[0]: size_t is just an indication that this variable can hold any index of an object or the size of an object. Hence, being used here.
// NOTE[1]: AlL Array Parameter can be done with *ArrToProcess as a Pointer.
bool ProcInit_MergeSort(unsigned int ArrToProcess[], unsigned int LeftArrayIndex, unsigned int RightArrayIndex);
void ProcData_MergeSort(unsigned int ArrToProcess[], unsigned int LeftArrayIndex, unsigned int MiddleArrayIndex, unsigned int RightArrayIndex);
void DisplayProc_MergeSort(unsigned int PayloadToRead[], size_t PayloadSize);

size_t Int_PayloadGlobal = INIT_NULL; // I cannot pass Int_PayloadSize due to recursion.
int main()
{
    //unsigned int Int_Payload[] = {12, 11, 13, 5, 6, 7}; // Parload #1, Goal
    unsigned int Int_Payload[] = {8, 1, 4, 1, 5, 9, 2, 6, 5}; // Parload #2, Supplementary Activity

    size_t Int_PayloadSize = (sizeof(Int_Payload) / sizeof(Int_Payload[INITIAL_INDEX])); // Calculate and Determine to Pass.
    Int_PayloadGlobal = Int_PayloadSize;
    DisplayProc_MergeSort(Int_Payload, Int_PayloadSize); // Display and Initialize the Static Variabe on THIS Function In Line from the comment.

    // LEARNED SOMETHING NEW: You can use ternary on return or any type of statement that can return something similar.
    return (ProcInit_MergeSort(Int_Payload, INITIAL_INDEX, Int_PayloadSize - POS_OFFSET_BY_ONE) ? DisplayProc_MergeSort(Int_Payload, Int_PayloadSize), OPERATION_SUCCESS : OPERATION_FAILED);
}

bool ProcInit_MergeSort(unsigned int ArrToProcess[], unsigned int LeftArrayIndex, unsigned int RightArrayIndex)
{
    if (LeftArrayIndex < RightArrayIndex)
    {
        unsigned int MiddleArrayIndex = LeftArrayIndex + (RightArrayIndex - LeftArrayIndex) / 2;
        ProcInit_MergeSort(ArrToProcess, LeftArrayIndex, MiddleArrayIndex);
        ProcInit_MergeSort(ArrToProcess, MiddleArrayIndex + POS_OFFSET_BY_ONE, RightArrayIndex);
        ProcData_MergeSort(ArrToProcess, LeftArrayIndex, MiddleArrayIndex, RightArrayIndex);
    }
    else
    {
        return OPERATION_FAILED; // If we are unable to do some process, then break and return OPERATION_FAILED(-1).
    }
}

void ProcData_MergeSort(unsigned int ArrToProcess[], unsigned int LeftArrayIndex, unsigned int MiddleArrayIndex, unsigned int RightArrayIndex)
{

    unsigned int *LeftSubArray, *RightSubArray,
        NumLeftElem = MiddleArrayIndex - LeftArrayIndex + POS_OFFSET_BY_ONE,
        NumRightElem = RightArrayIndex - MiddleArrayIndex, IterLeft = INIT_NULL,
        IterRight = INIT_NULL, IterRealArr = INIT_NULL;

    LeftSubArray = new unsigned int[NumLeftElem];
    RightSubArray = new unsigned int[NumRightElem];

    for (IterLeft = INIT_NULL; IterLeft < NumLeftElem; IterLeft++)
    {
        LeftSubArray[IterLeft] = ArrToProcess[LeftArrayIndex + IterLeft];
    }

    for (IterRight = INIT_NULL; IterRight < NumRightElem; IterRight++)
    {
        RightSubArray[IterRight] = ArrToProcess[MiddleArrayIndex + IterRight + POS_OFFSET_BY_ONE];
    }

    IterLeft = INIT_NULL, IterRight = INIT_NULL, IterRealArr = LeftArrayIndex;

    while (IterLeft < NumLeftElem && IterRight < NumRightElem)
    {
        if (LeftSubArray[IterLeft] <= RightSubArray[IterRight])
        {
            ArrToProcess[IterRealArr] = LeftSubArray[IterLeft];
            IterLeft++;
        }
        else
        {
            ArrToProcess[IterRealArr] = RightSubArray[IterRight];
            IterRight++;
        }
        IterRealArr++;
    }

    while (IterLeft < NumLeftElem)
    {
        ArrToProcess[IterRealArr] = LeftSubArray[IterLeft];
        DisplayProc_MergeSort(ArrToProcess, Int_PayloadGlobal);
        IterRealArr++;
        IterLeft++;
    }

    while (IterRight < NumRightElem)
    {
        ArrToProcess[IterRealArr] = RightSubArray[IterRight];
        DisplayProc_MergeSort(ArrToProcess, Int_PayloadGlobal);
        IterRealArr++;
        IterRight++;
    }
    delete[] LeftSubArray, RightSubArray;
}

void DisplayProc_MergeSort(unsigned int PayloadToRead[], size_t PayloadSize)
{
    static unsigned short DisplayCount;
    std::cout << SORT_TYPE << " | Pass Count " << DisplayCount << (!DisplayCount ? " Init. " : " ") << "|> ";
    for (auto DisplayArray = INIT_NULL; DisplayArray < PayloadSize; DisplayArray++)
    {
        std::cout << PayloadToRead[DisplayArray] << ((DisplayArray < PayloadSize - POS_OFFSET_BY_ONE) ? ", " : "");
    }
    std::cout << std::endl, DisplayCount++;
}
/* Laboratory Activity 6, Merge Sort on Strings, By Janrey Licas, CPE21FB1
DO NOT REDISTRIBUTE, IM WARNING YOU.
Level up your readibility if you have to.
*/