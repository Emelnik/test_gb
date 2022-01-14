// lesson7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "mylib.h"
#include <cmath> 
#include <string>
#include <fstream>
#define INRANGE (num >= 0 && num < range) ? "true":"false"
#define SIZE 7
//int a;
//int b;
#define SwapINT(a,b) int temp = arr2[a]; arr2[a] = arr2[b]; arr2[b] = temp; 

//Task2
std::string inRange(int range)
{
    int num(0);
    std::cout << "\n Enter number: \n";
    std::cin >> num;
    return INRANGE;
}

//Task3
void sortArr(int arr2[])
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE-1; j++)
        {
            if (arr2[j] > arr2[j + 1]) 
            {
                SwapINT(j, j+1);
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr2[i] << " "; 
    }
    system("pause");
}

//Task4
#pragma pack(push, 1)
struct Employee
{
    int TableNum;
    std::string Name;
    float Salary;
    bool Merried;
};
#pragma pack (pop)

int main()
{
    int range = 200;
    float arr1[15] = { 0 };
    //Task1,5
    mylib::initArr(arr1, 15);
    mylib::printArr(arr1, 15);
    mylib::parseArr(arr1, 15);
    
    //Task2
    std::cout << inRange(range) << std::endl;

    //Task3
    int arr2[SIZE] = { 0 };
    for (size_t i = 0; i < SIZE; i++)
    {
    std::cout << "Enter element "<< i<<": ";
    std::cin >> arr2[i];

    }
    sortArr(arr2);

    //Task4
    Employee* Engineer = new Employee;
    Engineer->Merried = true;
    Engineer->Name = "Eugene";
    Engineer->Salary = 150000.00;
    Engineer->TableNum = 29894;
    
    std::cout << Engineer->Merried << std::endl;
    std::cout << Engineer->Name << std::endl;
    std::cout << Engineer->Salary << std::endl;
    std::cout << Engineer->TableNum << std::endl;
    std::cout << sizeof(Engineer) << std::endl;

    std::ofstream fout("Empl.txt");
            fout << Engineer->Merried << std::endl;
            fout << Engineer->Name << std::endl;
            fout << Engineer->Salary << std::endl;
            fout << Engineer->TableNum << std::endl;
            fout.close();

    delete Engineer;

}

