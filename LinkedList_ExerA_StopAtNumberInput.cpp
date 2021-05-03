/*
    * |> Activity 5, Exercise A 5th Phase Alteration and Code Optimized
    * |> Linked List Programming Exercise A
    * |> Created by: Janrey "CodexLink" Licas, http://github.com/CodexLink
    * |> Modified for Github Exposure
    * |> Version: Revised State, Phase 1
    * |> Goal:
    * |> This code includes... 1. The Use of Preprocess Directives
    *                          2. Implementation of Custom Struct by TypeDef To Call In Different Name
    *                          3. Function Definition
    *                          4. The Use of VOID Function with Pass by Pointer
*/
#include <iostream> // Basic Input Output Library, Required

// Macro Definitions, Used Here for Anti-Magic Number Declarations
#define MAX_ACCEPTABLE_VAL_TAIL 10  //Maximum Condition Before Putting Value to Node_Tail.
#define INTEGER_SPECIAL_VALUE 999   //Special Value To Break from While Loop.
#define INTEGER_TARGET_SECONDNODE 2 // Limiter based on Objective. /* Reduced LinkedList_Node Usage to 1, Combined, Error Handled*/

// Typedef Struct for thrilling experience. Similar to Struct...
typedef struct LinkedList_Node
{
    signed short Int_Data;
    LinkedList_Node *NextNode;

} LinkedList_Node;

// ! Function Prototypes
void InsertNode(LinkedList_Node &, signed short RawData, bool); // Function Prototypes, Used for any values that is not a 999.
void DisplayList_Nodes(LinkedList_Node *);                      // Display All Nodes and dispose it all the way.

int main()
{
    LinkedList_Node *Node_ContainerList = NULL;
    bool RawData_MaxTrigger = false;
    signed short RawData = 0;

    // * This loop does not stop until the user entered a value INTEGER_SPECIAL_VALUE which is 999.
    while (!RawData_MaxTrigger)
    {
        std::cout << "Input a number (For Linked List Insertion) > ";
        std::cin >> RawData;
        (RawData == INTEGER_SPECIAL_VALUE) ? (RawData_MaxTrigger = true, InsertNode(*Node_ContainerList, RawData, true), DisplayList_Nodes(Node_ContainerList)) : InsertNode(*Node_ContainerList, RawData, false);
    }
}

void InsertNode(LinkedList_Node &TempContainerList, signed short RawData, bool isData_INTEGER_SPECIAL)
{
    LinkedList_Node *NewNode_Insertion = new LinkedList_Node, *TempNode_Container = TempContainerList;

    unsigned short Node_PosOffset = 0, ListNode_Iteration = 0, NodeSize = 0;
    NewNode_Insertion->Int_Data = RawData;
    NewNode_Insertion->NextNode = NULL;

    if (!isData_INTEGER_SPECIAL)
    {
        if (RawData <= MAX_ACCEPTABLE_VAL_TAIL)
        {
            NewNode_Insertion->NextNode = TempContainerList;
            TempContainerList = NewNode_Insertion;
        }
        else
        {
            if (TempContainerList == NULL)
            {
                TempContainerList = NewNode_Insertion;
            }
            else
            {
                while (TempNode_Container->NextNode != NULL)
                {
                    TempNode_Container = TempNode_Container->NextNode;
                }
                TempNode_Container->NextNode = NewNode_Insertion;
            }
        }
        NodeSize++;
    }
    else
    {
        (NodeSize < INTEGER_TARGET_SECONDNODE) ? (Node_PosOffset = NodeSize) : (Node_PosOffset = INTEGER_TARGET_SECONDNODE - 1);
        if (Node_PosOffset)
        {
            while (TempNode_Container->NextNode != NULL && ListNode_Iteration < Node_PosOffset)
            {
                TempNode_Container = TempNode_Container->NextNode;
                ListNode_Iteration++;
            }
            NewNode_Insertion->NextNode = TempNode_Container->NextNode;
            TempNode_Container->NextNode = NewNode_Insertion;
        }
        else
        {
            NewNode_Insertion->NextNode = NULL;
            TempContainerList = NewNode_Insertion;
        }
    }
}
void DisplayList_Nodes(LinkedList_Node *TempContainerList)
{
    std::cout << std::endl
              << "Linked List Contains > ";

    // * We display our Node Data until we reached address containing NULL.
    // ! Keep in mind that, while we iterated to this variable.
    // !All of the data iterated here will be deleted. Better Assign a Temp Variable Pointing to 'This' Iterable Varaible.
    while (TempContainerList != NULL)
    {
        std::cout << TempContainerList->Int_Data << " ";
        TempContainerList = TempContainerList->NextNode;
    }
}
/*
    * |> Activity 5, Exercise A 5th Phase Alteration and Code Optimized
    * |> Linked List Programming Exercise A
    * |> Created by: Janrey "CodexLink" Licas, http://github.com/CodexLink
    * |> Modified for Github Exposure
    * |> Version: Revised State, Phase 1
    * |> Goal:
    * |> This code includes... 1. The Use of Preprocess Directives
    *                          2. Implementation of Custom Struct by TypeDef To Call In Different Name
    *                          3. Function Definition
    *                          4. The Use of VOID Function with Pass by Pointer
    *
*/