#include <iostream> // Show Data from Container - Array Method, No Data Input Guards by Janrey Licas, CPE21FB1
#include <stack> // 1st Optimization, No Other Addtional Information Added.
int main()
{
	std::stack<int> Data_Container;
	unsigned short *SizeArray = NULL, Raw_IntData = 0, StackSize = 0, SumAve = 0;
	while (1)
	{
		std::cout << "Enter a number > ";
		std::cin >> Raw_IntData;
		if (Raw_IntData == 999)
		{
			std::cout << std::endl << "Hit 999... Pushing on Stack is finished with a layers size of " << StackSize << std::endl << "Numbers in Stack > ";
			SizeArray = new unsigned short[StackSize];
			for (short Iterator = StackSize - 1; Iterator >= 0; Iterator--)
			{
				SizeArray[Iterator] = Data_Container.top();
				Data_Container.pop();	
			}
			for (short Iterator = 0; Iterator < StackSize; Iterator++)
			{
				SumAve += SizeArray[Iterator];
				std::cout << SizeArray[Iterator] << " ";
			}
			std::cout << std::endl << "AVERAGE > " << ((float)SumAve / StackSize) << std::endl << "Program Execution Done...";
			delete [] SizeArray; // Might be optional, deletes array to avoid invalid memory pointer or something at the end of the execution.
			return 0; // EXIT_SUCCESS
		}
		else
		{
			Data_Container.push(Raw_IntData);
			StackSize++;
		}
	}
}
