// lesson5.cpp 
#include <iostream>

using namespace std;
 //task1 
void Printout(double arr[], int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << arr[j] << "\t";
	}
}
void Printout(int arr[], int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << arr[j] << "\t";
	}
}

//task2
void ChangBit(int *numbers2, const size_t SIZE)
{
	Printout(numbers2, SIZE);
	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		numbers2[i] = numbers2[i]<1;
	}
	Printout(numbers2, SIZE);
}

//task3
void Fill(int* arr3, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		arr3[i] = i * 3 + 1;
	}
}

//task4
void Shift(int* arr4, int dir, int size)
{
	Printout(arr4, size);
	cout << endl;
	if (dir >= 0)
	{
		//left
		for (int j = 0; j < dir; j++)
		{
			int temp = arr4[0];
			for (int i = 0; i < size - 1; i++)
			{
				arr4[i] = arr4[i + 1];
			}
			arr4[size - 1] = temp;
		}
		Printout(arr4, size);
	}
	else
	{
		//right
		for (int j = dir; j < 0; j++)
		{
			int temp = arr4[size-1];
			for (int i = size - 1; i > 0; i--)
			{
				arr4[i] = arr4[i - 1];
			}
			arr4[0] = temp;
		}
		Printout(arr4, size);
	}
}

//task5
bool Balance(int* arr5, int size)
{
	int sum_l = 0;
	int sum_r = 0;
	for (size_t i = 1; i < size; i++)
	{
		for (size_t l = 0; l < i; l++)
		{
			sum_l = sum_l + arr5[l];
		}
		for (size_t r = size-1; r >= i; r--)
		{
			sum_r = sum_r + arr5[r];
		}
		if (sum_l == sum_r)
			return true;
		sum_r = 0;
		sum_l = 0;
	}
return false;
}


int main()
{
	//1.
	cout << endl<<"task1"<<endl;
	double numbers[] = {23,56,7,6,434,52.35435,487875,64,76,34,33};
	Printout(numbers, 11);
	

	//2.
	cout << endl<<"task2" << endl;
	int numbers2[] = { 1,1,0,0,1,0,1,0,0,1 };
	ChangBit(numbers2,10);
	
	//3.
	cout << endl<<"task3" << endl;
	int arr3[8] = {0};
	Fill(arr3, 8);
	Printout(arr3, 8);
	
	//4.
	cout << endl << "task4" << endl;
	int arr4[] = { 12,3,45,3,2,6,0,0,786,15,1,4,55 };
	int dir = -4;
	int size = sizeof(arr4) / sizeof(arr4[0]);
	Shift(arr4, dir, size);

	//5.
	cout << endl << "task5" << endl;
	int arr5[] = { 2,1,17,4,3,2,17,4,3,1};
	int size5 = sizeof(arr5) / sizeof(arr5[0]);
	cout << Balance(arr5, size5);
}

