// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Игра "Крестики-нолики"
//


#include <iostream>
// task 1
short int ScorePlayr1 = 0, ScorePlayr2 = 0;
int StepCount{ 0 };
long long a = 8765432;
char Round = 0, PlayrName1 [], PlayrName2[];
bool FlagComplete = false;
float MoveDuration{ 0.00f };
double GameDuration = 0.0f;

// task 2
enum Symbols:char {zero = '0', cross = 'x', empty = '_' };

//task 3
Symbols GameAry[3][3] = { {cross, empty, empty}, {empty, cross, empty}, {empty, empty, cross}};


// task 4
struct GameFeeld
{
    char Round;
    char NamePlayer1[255];
    char NamePlayer2[255];
    char SymbolByPlayer1;
    char SymbolByPlayer2;
    int ScorePlayer1;
    int ScorePlayer2;
    char PlayerIdAccessNow ; // номер игрока, кому разрешено делать ход. 1, 2.
    char CurentFild[3][3]; //матрица поля
    char CountLineSymbolPlayer1; // максимальное число символов в линию игрока 1
    char CountLineSymbolPlayer2; // максимальное число символов в линию игрока 2
 };

// task 5 
// ...?
  union MyData
    {
        int a;
        float b;
        char c;
    };

struct MyVariant
{
    MyData data;
    unsigned char isInt : 1;
    unsigned char isFloat : 1;
    unsigned char isChar : 1;
};



int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << GameAry[i][j] << "\t";
        std::cout << '\n';
    }
        std::cout << cross << "\n";
        std::cout << empty << "\n";
        std::cout << zero << "\n";
        std::cout << '\n';
        std::cout << '\n';

        MyVariant var;
        var.data.b = 77.77777f;
        var.isChar = 0;
        var.isFloat = 1;
        var.isInt = 0;
        std::cout << var.data.b << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
