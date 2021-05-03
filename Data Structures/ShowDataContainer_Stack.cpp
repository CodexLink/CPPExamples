#include <iostream> // Show Data from Container - Stack Method, No Data Type Guards by Janrey Licas, CPE21FB1.
#include <stack> // 1st Optimization, Reduced Intialization Redundants...
int main()
{
	std::stack<int> Int_Container_1, Int_Container_2;
	unsigned short Raw_IntData = 0, StackSize = 0, SumAve = 0;
	while (1)
	{
		std::cout << "Enter a number > ";
		std::cin >> Raw_IntData;
		if (Raw_IntData == 999)
		{
			std::cout << std::endl << "Hit 999... Pushing on Stack is finished with a layers size of " << StackSize << std::endl << "Numbers in Stack > ";
			while (!Int_Container_1.empty())
			{
				Int_Container_2.push(Int_Container_1.top());
				Int_Container_1.pop();
			}
			while (!Int_Container_2.empty())
			{
				std::cout << Int_Container_2.top() << " ";
				SumAve += Int_Container_2.top();
				Int_Container_2.pop();
			}
			std::cout << std::endl << "AVERAGE > " << ((float)(SumAve / StackSize)) << std::endl << "Program Execution Done...";
			return 0; // EXIT_SUCCESS
		}
		else
		{
			Int_Container_1.push(Raw_IntData);
			StackSize++;
		}
	}
}