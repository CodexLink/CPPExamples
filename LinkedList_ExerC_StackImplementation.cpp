#include <iostream>
#include <string.h>
#include <stdlib.h>
typedef struct LinkedList_Node // Typedef Struct for thrilling experience. Similar to Struct...
{
	signed short Int_Data;
	LinkedList_Node *NextNode;
} LinkedList_Node;
LinkedList_Node *Node_StackContainer = NULL;
unsigned short RawData_ToNode = 0, Node_MainSize = 0;
char cmd_NodeArg[10] = {0};

void NodeList_Stack_Pop();
void NodeList_Stack_Push(unsigned short Node_IntValue);
void NodeList_Stack_Peek();
void NodeList_Stack_DisplayContent();
int main()
{
	std::cout << "Stack Simulation on Singly Linked List, Available Commands: (PUSH, PEEK, POP, and PRINT_CONTENT [Case Sensitive])" << std::endl;
	while (1)
	{
		std::cout << "[INPUT] Enter Command > ";
		std::cin >> cmd_NodeArg;
		if (strcmp(cmd_NodeArg, "POP") == 0)
		{
			NodeList_Stack_Pop();
			continue;
		}
		else if (strcmp(cmd_NodeArg, "PUSH") == 0)
		{
			std::cout << "[INPUT] Integer Value (Must Be Atomic, Singular)] > ";
			std::cin >> RawData_ToNode;
			NodeList_Stack_Push(RawData_ToNode);
			continue;
		}
		else if (strcmp(cmd_NodeArg, "PEEK") == 0)
		{
			NodeList_Stack_Peek();
			continue;
		}
		else if (strcmp(cmd_NodeArg, "PRINT_CONTENT") == 0)
		{
			NodeList_Stack_DisplayContent();
			continue;
		}
		else
		{
			std::cout << "[ERROR] Invalid Parameters, Please Try Again..." << std::endl
					  << std::endl;
			continue;
		}
		std::cout << "[PROGRAM TERMINATE] Process Execution Done...";
		return 0;
	}
}
void NodeList_Stack_Pop()
{
	LinkedList_Node *ListModifier = Node_StackContainer;
	if (ListModifier != NULL)
	{
		Node_StackContainer = ListModifier->NextNode;
		free(ListModifier);
		Node_MainSize--;
		std::cout << "[PROCESS] Popping Top Value Success!" << std::endl;
	}
	else
	{
		std::cout << "[ERROR] Node Container is currently empty!" << std::endl;
	}
}
void NodeList_Stack_Peek()
{
	LinkedList_Node *TempContainer_Iteration = Node_StackContainer;
	if (TempContainer_Iteration != NULL)
	{
		std::cout << "[RESULT] Current Top Integer Value > " << TempContainer_Iteration->Int_Data << std::endl;
	}
	else
	{
		std::cout << "[ERROR] Node Container is currently empty!" << std::endl;
	}
}
void NodeList_Stack_Push(unsigned short Node_IntValue)
{
	LinkedList_Node *NewNodeInsertion = new LinkedList_Node, *TempContainer_Iteration = Node_StackContainer;
	NewNodeInsertion->Int_Data = Node_IntValue;
	NewNodeInsertion->NextNode = NULL;
	if (Node_StackContainer == NULL)
	{
		Node_StackContainer = NewNodeInsertion;
	}
	else
	{
		NewNodeInsertion->NextNode = Node_StackContainer;
		Node_StackContainer = NewNodeInsertion;
	}
	Node_MainSize++;
	std::cout << "[RESULT, PROCESS] Succesfully Pushed " << Node_IntValue << " to Node Container!" << std::endl;
}
void NodeList_Stack_DisplayContent()
{
	LinkedList_Node *NodeRead_TempContainer = Node_StackContainer;
	if (Node_MainSize)
	{
		std::cout << "[RESULT] Current Node Container Elements > ";
		while (NodeRead_TempContainer != NULL)
		{
			std::cout << NodeRead_TempContainer->Int_Data << " ";
			NodeRead_TempContainer = NodeRead_TempContainer->NextNode;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "[ERROR] Node Container is currently empty!" << std::endl
				  << std::endl;
	}
}