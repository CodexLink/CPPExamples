#include <iostream> // Positional Tracking with New Stack Pushed with Target Number Excluded from Push
#include <queue> // 2nd Optimization + Minified, Lines of Code went from 70+ to 45 Lines of Code, By Janrey Licas @ CPE21FB1
int main() // Can be lessen up to 40 lines and below, all additional outputs has been retained.
{
	std::queue<int> Num_Container_1, Num_Container_2;
	unsigned short Stack_Incrementor = 0, RawData = 0, DataTarget = 0, PositionValueTrack = 1, AverageComp = 0;
	while (1)
	{
		std::cout << "Enter a number > ";
		std::cin >> RawData;
		if (RawData == 999)
		{
			std::cout << "Enter a target number to be searched from the stack > ";
			std::cin >> DataTarget;
			std::cout << std::endl << "Integer Target > " << DataTarget << std::endl << "The Position of " << DataTarget << " is ";
			while (!Num_Container_1.empty())
			{
				if (DataTarget == Num_Container_1.front())
				{
					std::cout << PositionValueTrack << " ";
				}
				else
				{
					Num_Container_2.push(Num_Container_1.front());
					Stack_Incrementor++;
				}
				Num_Container_1.pop();
				PositionValueTrack++;
			}
			std::cout << std::endl << std::endl << "NEW QUERY CONTENT with New Stack Size of " << Stack_Incrementor << " > ";
			while (!Num_Container_2.empty())
			{
				std::cout << Num_Container_2.front() << " ";
				AverageComp += Num_Container_2.front();
				Num_Container_2.pop();
			}
			std::cout << std::endl << "AVERAGE > " << ((float)AverageComp / Stack_Incrementor) << std::endl << "Program Execution Done...";
			return 0;
		}
		else
		{
			Num_Container_1.push(RawData);
		}
	}
}