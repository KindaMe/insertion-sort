#include <iostream>
#include <vector>
#include <utility>

void sort(std::vector<int>& numbersPtr);
void printN(std::vector<int> numbers, int range);

void premadeTest();
void ownNumbers();

int main()
{
	std::string choice;

	do
	{
		system("cls");

		std::cout << "Choose mode:\n\n1 - Premade test\n2 - Your own numbers\n\nX - Exit\n";
		std::cin >> choice;

		switch (tolower(choice[0]))
		{
		case '1':
			premadeTest();
			break;
		case '2':
			ownNumbers();
			break;
		case 'x':
			return 0;
		default:
			break;
		}

		std::cout << "Press enter to continue...";
		std::cin.ignore(1000, '\n');
		std::cin.get();
	} while (true);
}

void sort(std::vector<int>& numbersPtr)
{
	int range = 0;
	int swaps = 0;

	for (int i = 0; i < numbersPtr.size(); i++)
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

void premadeTest()
{
	std::vector<int> randomOrder = { 94,18,12,55,42,44,6,67 };
	std::vector<int> correctOrder = { 6,12,18,42,44,55,67,94 };
	std::vector<int> reversedOrder = { 94,67,55,44,42,18,12,6 };

	system("cls");

	std::cout << std::string(50, '-') << "\n";
	std::cout << "Numbers in random order: ";
	printN(randomOrder, randomOrder.size() - 1);
	std::cout << "\n";
	sort(randomOrder);

	std::cout << std::string(50, '-') << "\n";
	std::cout << "Numbers in correct order: ";
	printN(correctOrder, correctOrder.size() - 1);
	std::cout << "\n";
	sort(correctOrder);

	std::cout << std::string(50, '-') << "\n";
	std::cout << "Numbers in reversed order: ";
	printN(reversedOrder, reversedOrder.size() - 1);
	std::cout << "\n";
	sort(reversedOrder);

	std::cout << std::string(50, '-') << "\n";
}

void ownNumbers()
{
	int size;
	std::vector<int> numbers;
	int input;

	do
	{
		system("cls");

		std::cout << "Size: ";

		if (std::cin >> size)
		{
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);

	for (int i = 0; i < size; i++)
	{
		do
		{
			system("cls");
			std::cout << "[" << i + 1 << "/" << size << "]:";

			if (std::cin >> input)
			{
				numbers.push_back(input);
				break;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (true);
	}

	system("cls");

	std::cout << "Numbers: ";
	printN(numbers, size - 1);
	std::cout << "\n";

	sort(numbers);
}