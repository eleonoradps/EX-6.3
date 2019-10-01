#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>


// exercice 6.3


void BubbleSort(std::vector<unsigned short>& vec)
{
	for (int n = 0; n < vec.size() - 1; n++) 
	{
		for (int i = 0; i < vec.size() - n - 1; i++)
		{
			if (vec[i] > vec[i + 1])
			{
				int temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << " " << vec[i];
	}

	std::cout << "\n";
}

void InsertionSort(std::vector<unsigned short>& vec)
{
	for (int n = 1; n < vec.size(); n++)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			if (vec[k] > vec[k + 1])
			{
				int temp = vec[k];
				vec[k] = vec[k + 1];
				vec[k + 1] = temp;
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void QuickSort(std::vector<unsigned short>& vec, int left, int right)
{
	int i = left;
	int j = right;
	int temp;
	int pivot = vec[(left + right) / 2];

	//partitionnement

	while (i <= j)
	{
		while (vec[i] < pivot)
			i++;
		while (vec[j] > pivot)
			j--;

		if (i <= j)
		{
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			i++;
			j--;
		}

	};

	//recursion

	if (left < j)
	{
		QuickSort(vec, left, j);
	}
	if (i < right)
	{
		QuickSort(vec, i, right);
	}
}

int main() 
{
	int Choice;
	int ElemChoice;


	std::cout << "Choisissez un algorithme de tri \n";
	std::cout << "Bubble Sort = 1 \n";
	std::cout << "Insertion Sort = 2 \n";
	std::cout << "Quick Sort = 3 \n";
	std::cin >> Choice;

	std::cout << "How many elements do you want in your sort function ? \n";
	std::cin >> ElemChoice;

	std::vector<unsigned short>numbers;
	numbers.resize(ElemChoice);

	srand(time(NULL));

	for (int i = 0; i < ElemChoice; i++)
	{
		numbers[i] = rand() % 32767;
	}

	switch (Choice)
	{
	case 1:
		std::cout << "Here is your result : \n"; 
		BubbleSort(numbers);
		break;

	case 2:
		std::cout << "Here is your result : \n";
			InsertionSort(numbers);
		break;

	case 3:
		std::cout << "Here is your result : \n";
			QuickSort(numbers, 0, numbers.size() - 1);
			for (int i = 0; i < numbers.size(); i++)
			{
				std::cout << numbers[i] << " ";
			}
			std::cout << "\n";
			break;
	}



}