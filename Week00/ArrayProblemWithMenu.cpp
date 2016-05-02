#include "iostream"
using namespace std;

const int MAX_CAPACITY = 100;
bool isSortedAscending = false, isSortedDescending = false;

void ArrInput(int *arr, int &numOfElements)
{
	for (int i = 0; i < numOfElements; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}

bool CheckForNumber(int *arr, int numOfElements, int userNum)
{
	for (int i = 0; i < numOfElements; i++)
	{
		if (arr[i] == userNum)
			return true;
	}
	return false;
}

void BubbleSortAscending(int *arr, int numOfElements)
{
	if (isSortedAscending)
		return;

	for (int i = 0; i < numOfElements - 1; i++)
	{
		for (int j = 0; j < numOfElements - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	isSortedAscending = true;
	isSortedDescending = false;
}

void BubbleSortDescending(int *arr, int numOfElements)
{
	if (isSortedDescending)
		return;

	for (int i = 0; i < numOfElements - 1; i++)
	{
		for (int j = 0; j < numOfElements - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	isSortedDescending = true;
	isSortedAscending = false;
}

void SelectionSortAscending(int *arr, int numOfElements)
{
	if (isSortedAscending)
		return;

	int minIndex;
	for (int i = 0; i < numOfElements - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < numOfElements; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	isSortedAscending = true;
	isSortedDescending = false;
}

void SelectionSortDescending(int *arr, int numOfElements)
{
	if (isSortedDescending)
		return;

	int minIndex;
	for (int i = 0; i < numOfElements - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < numOfElements; j++)
		{
			if (arr[j] > arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	isSortedDescending = true;
	isSortedAscending = false;
}

int GetMax(int *arr, int numOfElements)
{
	if (isSortedAscending)
		return arr[numOfElements - 1];
	else if (isSortedDescending)
		return arr[0];

	int max = arr[0];
	for (int i = 1; i < numOfElements; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int GetMin(int *arr, int numOfElements)
{
	if (isSortedAscending)
		return arr[0];
	else if (isSortedDescending)
		return arr[numOfElements - 1];

	int min = arr[0];
	for (int i = 1; i < numOfElements; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

double GetMedian(int *arr, int numOfElements)
{
	int tempArr[numOfElements];
	for(int i = 0; i < numOfElements; i++)
		tempArr[i] = arr[i];
	BubbleSortAscending(tempArr, numOfElements);
	isSortedAscending = false;
	isSortedDescending = false;

	if (numOfElements % 2 != 0)
		return tempArr[numOfElements / 2];
	else
	{
		double median = (tempArr[numOfElements / 2] + tempArr[numOfElements / 2 - 1]) / 2.0;
		return median;
	}
}

double GetAverage(int *arr, int numOfElements)
{
	int sum = 0;
	for (int i = 0; i < numOfElements; i++)
		sum += arr[i];

	return (sum / (double)numOfElements);
}

void PrintArr(int *arr, int numOfElements)
{
	for (int i = 0; i < numOfElements; i++)
	{
		if (i != numOfElements - 1)
			cout << arr[i] << ", ";
		else
			cout << arr[i] << endl;
	}
}

void PrintHelp()
{
	cout << "------------------" << endl;
	cout << "1 -> Array input" << endl;
	cout << "2 -> Overwrite the array" << endl;
	cout << "3 -> Sort array" << endl;
	cout << "4 -> Check if a specific integer is in the array" << endl;
	cout << "5 -> Get max element" << endl;
	cout << "6 -> Get min element" << endl;
	cout << "7 -> Get the median of the array" << endl;
	cout << "8 -> Get the average of the elements in the array" << endl;
	cout << "9 -> Print array elements" << endl;
	cout << "? -> Print the full list of commands" << endl;
	cout << "# -> Exit the program" << endl;
	cout << "------------------" << endl;
}

int main()
{
	int arr[MAX_CAPACITY];
	int numOfElements = -1;
	int sortChoice, ascendingChoice;
	bool sortAscending = true;

	char userInput = '.';
	cout << "Welcome!" << endl;
	cout << "Enter '?' for a full list of commands." << endl;
	while (true)
	{
		cin >> userInput;
		switch (userInput)
		{
		case '1':
			cout << "How many elements do you want to enter? " << endl;
			cin >> numOfElements;
			ArrInput(arr, numOfElements);
			break;
		case '2':
			cout << "Overwrite the array:" << endl;
			ArrInput(arr, numOfElements);
			isSortedAscending = false;
			isSortedDescending = false;
			break;
		case '3':
			cout << "Choose a sorting algorithm:" << endl;
			cout << "Bubble sort -> press '1'" << endl;
			cout << "Selection sort -> press '2'" << endl;
			cin >> sortChoice;
			while (sortChoice != 1 && sortChoice != 2)
			{
				cout << "Try again, invalid command!" << endl;
				cin >> sortChoice;
			}

			cout << "Ascending or Descending?" << endl;
			cout << "Ascending -> press '1'" << endl;
			cout << "Descending -> press '0'" << endl;
			cin >> ascendingChoice;
			while (ascendingChoice != 0 && ascendingChoice != 1)
			{
				cout << "Try again, invalid command!" << endl;
				cin >> ascendingChoice;
			}
			sortAscending = ascendingChoice;

			if (sortChoice == 1)
			{
				if (sortAscending)
					BubbleSortAscending(arr, numOfElements);
				else
					BubbleSortDescending(arr, numOfElements);
			}
			else
			{
				if (sortAscending)
					SelectionSortAscending(arr, numOfElements);
				else
					SelectionSortDescending(arr, numOfElements);
			}

			break;
		case '4':
			int userNumber;
			cout << "Enter an integer: ";
			cin >> userNumber;
			if (CheckForNumber(arr, numOfElements, userNumber))
				cout << "The number is in the array." << endl;
			else
				cout << "The number is not in the array." << endl;
			break;
		case '5':
			cout << "The maximum element is: " << GetMax(arr, numOfElements) << endl;
			break;
		case '6':
			cout << "The minimum element is: " << GetMin(arr, numOfElements) << endl;
			break;
		case '7':
			cout << "The median is: " << GetMedian(arr, numOfElements) << endl;
			break;
		case '8':
			cout << "The average is: " << GetAverage(arr, numOfElements) << endl;
			break;
		case '9':
			PrintArr(arr, numOfElements);
			break;
		case '?':
			PrintHelp();
			break;
		case '#':
			return 0;
		default:
			cout << "Write '?' for the full list of commands" << endl;
			break;
		}
	}
	return 0;
}
