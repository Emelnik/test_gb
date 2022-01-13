#include <iostream>

namespace mylib
{
	void initArr(float* arr1, int size) //?почему size_t нельзя 
	{
		for (size_t i = 0; i < size; i++)

			arr1[i] = sin(i);
	}

	void printArr(float* arr1, int size)
	{
		for (size_t i = 0; i < size; i++)

			std::cout << arr1[i] << " ";
	}

	void parseArr(float* arr1, int size) //? как передать в функцию только массив, а кол-во его элементов определить в самой функции

	{
		int pos = 0;
		int neg = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr1[i] > 0)
			{
				pos++;
			}
			if (arr1[i] < 0)
			{
				neg++;
			}

			//std::cout << std::endl;
			//std::cout << sizeof (arr1[]);
		}
		std::cout << std::endl;
		std::cout << "positive elements: " << pos << std::endl;
		std::cout << "negative elements: " << neg << std::endl;
	}
};

