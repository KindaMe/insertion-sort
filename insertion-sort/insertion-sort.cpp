#include <iostream>
#include <vector>
#include <utility>

void sort(std::vector<int>& numbersPtr, int size);
void printN(std::vector<int> numbers, int range);

int main()
{
	int size;
	std::vector<int> numbers;

	std::cout << "Size: ";
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		int input;

		std::cin >> input;
		numbers.push_back(input);
	}

	system("cls");

	std::cout << "Numbers: ";
	printN(numbers, size - 1);
	std::cout << "\n";

	sort(numbers, size);

	return 0;
}

void sort(std::vector<int>& numbersPtr, int size)
{
	int range = 0;
	int swaps = 0;

	for (int i = 0; i < size; i++)
	{
		std::cout << "\nIndex range = " << range << "\n";
		printN(numbersPtr, range);
		std::cout << "- before" << "\n";

		for (int j = range; j > 0; j--)
		{
			if (numbersPtr[j] < numbersPtr[j - 1])
			{
				std::swap(numbersPtr[j], numbersPtr[j - 1]);
				swaps++;

				printN(numbersPtr, range);
				std::cout << "\n";
			}
		}
		printN(numbersPtr, range);
		std::cout << "- after" << "\n";
		range++;
	}

	std::cout << "\nSwaps: " << swaps << "\n";
}

void printN(std::vector<int> numbers, int range)
{
	for (int i = 0; i <= range; i++)
	{
		std::cout << numbers[i] << " ";
	}
}