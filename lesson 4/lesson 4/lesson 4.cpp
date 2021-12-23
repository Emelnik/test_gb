// lesson 4.cpp 

#include <iostream>

using namespace std;

//сумма двух
//(введенных с клавиатуры) чисел лежит в пределах от 10 до 20
//(включительно), если да – вывести строку "true", в противном
//случае – "false";
void Task1(void)
{
    float a{ 0.0f }, b{ 0.0f };
    const int LowLim = 10;
    const int UpLim = 20;
    cout << "First Number: ";
    cin >> a;
    cout << "Second Number: ";
    cin >> b;
    if ((a + b) >= LowLim && (a + b) <= UpLim)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
}

//строку “true”, если
//две целочисленные константы, объявленные в её начале либо
//обе равны десяти сами по себе, либо их сумма равна десяти.
//Иначе "false".
void Task2(void)
{
    int Const1 = 5;
    int Const2 = 6;
    if (Const1 == 10 || Const2 == 10 || Const1 + Const2 == 10)
        cout << "True\n";
    else
        cout << "False\n";
}

//список всех
//нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9
void Task3(void)
{
    cout << "Your numbers: ";
    for (size_t i = 1; i <= 50; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << ", ";
        } 
    }
}


//является ли некоторое число - простым.
void Task4(void)
{
    cout << "\n";
    cout << "Enter number: ";
    int j;
    cin >> j;
    int NoSimplFlag = 0;
    for (int i = 2; i < j; i++)
    {
        if (j % i == 0)
        {
            NoSimplFlag++;
        }
    }
    if (!NoSimplFlag)
        cout << j << " - is simple!";
    else
        cout << j << " - no simple";
}

// определяет является ли этот год високосным
void Task5(void)
{
    cout << "\n";
    cout << "Enter year: ";
    int year;
    cin >> year;
        if ((year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0)))
        {
            cout << year << " Leap Year\n";
        }
        else 
            cout << year << " not Leap Year\n";
}


int main()
{   
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
    return 0;
}
