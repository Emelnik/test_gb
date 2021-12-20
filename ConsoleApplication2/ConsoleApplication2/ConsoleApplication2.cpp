// Урок 3. Операции и выражения. ConsoleApplication2.cpp 

#include <iostream>

//int a = 3, b = 4, c = 5, d = 9;
extern int a, b, c, d;

int x = 26;
float result1 (0.0f);
int result2;
const int compare = 21;
int diff;


int main()
{
    //task 1
    int a = 3, b = 4, c = 5, d = 9;
    result1 = a * (b + (static_cast <float>(c) / d)); 
    std::cout << result1 << "\n";
    
    //task 2
    diff = x - compare;
    result2 = (x <= compare) ? (diff) : (diff * 2);
    std::cout << result2 << "\n";

    //task 3
    int Array[3][3][3];
    int* ptr = &Array[1][1][1];
    std::cout << "ptr = " << ptr << "  " << "*ptr =" << *ptr << std::endl;



    //task 4
    result1 = ::a * (::b + (static_cast <float>(::c) / ::d));
    std::cout << result1 << "\n";


    return 0;
}
