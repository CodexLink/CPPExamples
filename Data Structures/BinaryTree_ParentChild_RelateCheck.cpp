// Binary Tree Parent-Child Relationship
// Modified by Janrey Licas @ CPE21FB1
#include <iostream>
struct Node
{
	int NodeCurrent_Data;
	struct Node *LeftTreeNode, *RightTreeNode;
};

signed int printLeafNodes(Node *RootTreeNode, signed int ValTarget_One, signed int ValTarget_Two)
{
	if (!RootTreeNode)
		return 0;

	if (RootTreeNode->LeftTreeNode && RootTreeNode->RightTreeNode && (RootTreeNode->NodeCurrent_Data == ValTarget_One))
	{
		//cout << RootTreeNode->NodeCurrent_Data << " ";
		unsigned int LeftTreeNode = RootTreeNode->LeftTreeNode->NodeCurrent_Data;
		unsigned int RightTreeNode = RootTreeNode->RightTreeNode->NodeCurrent_Data;

		if (LeftTreeNode == ValTarget_Two || RightTreeNode == ValTarget_Two)
		{
			std::cout << ValTarget_One << " PARENT" << std::endl;
			std::cout << ValTarget_Two << " CHILD" << std::endl;
			exit(0);
		}
	}

	if (RootTreeNode->LeftTreeNode)
	{
		printLeafNodes(RootTreeNode->LeftTreeNode, ValTarget_One, ValTarget_Two);
	}
	if (RootTreeNode->RightTreeNode)
	{
		printLeafNodes(RootTreeNode->RightTreeNode, ValTarget_One, ValTarget_Two);
	}

	return 1;
}

Node *newNode(int NodeCurrent_Data)
{
	Node *TempNode = new Node;
	TempNode->NodeCurrent_Data = NodeCurrent_Data;
	TempNode->LeftTreeNode = TempNode->RightTreeNode = NULL;
	return TempNode;
}

int main()
{
	signed int NodeVal_1 = 0, NodeVal_2 = 0;
	Node *RootTreeNode = newNode(1);
	RootTreeNode->LeftTreeNode = newNode(2);
	RootTreeNode->RightTreeNode = newNode(3);
	RootTreeNode->LeftTreeNode->LeftTreeNode = newNode(4);
	RootTreeNode->LeftTreeNode->RightTreeNode = newNode(5);
	RootTreeNode->RightTreeNode->LeftTreeNode = newNode(6);
	RootTreeNode->RightTreeNode->RightTreeNode = newNode(7);
	RootTreeNode->LeftTreeNode->LeftTreeNode->LeftTreeNode = newNode(8);
	RootTreeNode->LeftTreeNode->LeftTreeNode->RightTreeNode = newNode(9);
	RootTreeNode->LeftTreeNode->RightTreeNode->LeftTreeNode = newNode(10);
	RootTreeNode->LeftTreeNode->RightTreeNode->RightTreeNode = newNode(11);
	RootTreeNode->RightTreeNode->LeftTreeNode->RightTreeNode = newNode(13);
	RootTreeNode->RightTreeNode->RightTreeNode->RightTreeNode = newNode(14);

	std::cin >> NodeVal_1 >> NodeVal_2;
	std:: cout << (printLeafNodes(RootTreeNode, NodeVal_1, NodeVal_2) ? "NO RELATIONSHIP" : 0) << std::endl;
	return 0;
}