// lesson8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include<stdlib.h>
#include<chrono>

using namespace std;

enum TCell : char {
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'
};

enum TProgress {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};
struct TCoord {
    size_t y;
    size_t x;
};

    struct TGame {
    TCell** ppField{ nullptr };
    const size_t size{ 3 };
    TCell human {CROSS};
    TCell ai{ZERO};
    size_t turn{ 0 }; //четн - человек
    TProgress progress{ IN_PROGRESS };
};

    void clearScr()
    {
        //system("cls");
        std::cout << "\x1B[2J\x1B[H";
}

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}


void initGame(TGame& g)
{
    g.ppField = new TCell * [g.size];
    for (size_t i = 0; i < g.size; i++)
    {
        g.ppField[i] = new TCell[g.size];
    }
    for (size_t y = 0; y < g.size; y++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }
    if (getRandomNum(0, 1000)>500)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
}

void deinitGame(TGame & g)
{
    for (size_t i = 0; i < g.size; i++)
    {
        delete [] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;

} 
void printGame(const TGame& g)
{
    system("Color 02");
    cout << "turn:" << g.turn;
    cout << endl;
    cout << " y\\x  ";
    for (size_t x = 0; x < g.size; x++)
       cout << x + 1 << "   ";
       cout << endl;
       
    for (size_t y = 0; y < g.size; y++)
    {
        cout << " " << y + 1 << " | ";
        for (size_t x = 0; x < g.size; x++)
        {
            cout << g.ppField[y][x] << " | " ;
        }
        cout << endl;
    }
    cout << endl << " Human: " << g.human << endl << " Computer: " << g.ai << endl;
}


TProgress getWon(const TGame& g)
{
    for (size_t y = 0; y < g.size; y++) //в строках..
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
                return WON_HUMAN;
            if (g.ppField[y][0] == g.ai)
                return WON_AI;
        }
    }
    for (size_t x = 0; x < g.size; x++) //в столбцах..
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
                return WON_HUMAN;
            if (g.ppField[0][x] == g.ai)
                return WON_AI;
        }
    }
        //диагональ э\э
        if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
        {
            if (g.ppField[0][0] == g.human)  
                return WON_HUMAN;
            if (g.ppField[0][0] == g.ai)
                return WON_AI;
        }
        //диагональ э/э
        if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[0][2])
        {
            if (g.ppField[1][1] == g.human)
                return WON_HUMAN;
            if (g.ppField[1][1] == g.ai)
                return WON_AI;
        }
        //ничья 
        bool draw{ true };
        for (size_t y = 0; y < g.size; y++)
        {
            for (size_t x = 0; x < g.size; x++)
            {
                if (g.ppField[y][x] == EMPTY)
                {
                    draw = false;
                    break;
                }
            }
            if (!draw)
                break;
        }
        if (draw)
            return DRAW;

        return IN_PROGRESS;
}

TCoord getHumanCoord(const TGame& g)
{
    TCoord c;
    do
    {
        cout << "Enter X (1-3):";
        cin >> c.x;
        cout << "Enter Y (1-3): ";
        cin >> c.y;
        c.x--;
        c.y--;
    } while (c.x > 2 || c.y > 2 || g.ppField[c.y][c.x] != EMPTY);
    return c;
}

TCoord getAICoord(TGame& g)
{
    //1предвыигрыш
   for (size_t y = 0; y < g.size; y++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y, x };
                } 
                g.ppField[y][x] = EMPTY;
            }
        }
        
    }
   
    // 2 предпроигрыш - мешать человеку победный ход
   for (size_t y = 0; y < g.size; y++)
   {
       for (size_t x = 0; x < g.size; x++)
       {
           if (g.ppField[y][x] == EMPTY)
           {
               g.ppField[y][x] = g.human;
               if (getWon(g) == WON_HUMAN)
               {
                   g.ppField[y][x] = EMPTY;
                   return { y, x };
               }
               g.ppField[y][x] = EMPTY; 
           }
       }

   }
   
    //3 приоритет углов случайно
    if (g.ppField[1][1] == EMPTY)
    {
        return{ 1, 1 };//центр
    }
    
    TCoord buf[4];  //углы
    size_t num{ 0 };
    if (g.ppField[0][0] == EMPTY)
    {
        buf[num] = { 0, 0 };
        num++;
    }
    if (g.ppField[2][2] == EMPTY)
    {
        buf[num] = { 2, 2 };
        num++;
    }  
    if (g.ppField[0][2] == EMPTY)
    {
        buf[num] = { 0, 2 };
        num++;
    }
    if (g.ppField[2][0] == EMPTY)
    {
        buf[num] = { 2, 0 };
        num++;
    }
    if (num > 0) 
    {
        const size_t index = rand() % num;
        return buf[index];
    } 
    //не углы
    num = 0;
    if (g.ppField[0][1] == EMPTY)
    {
        buf[num] = { 0, 1 };
        num++;
    }
    if (g.ppField[1][0] == EMPTY)
    {
        buf[num] = { 1, 0 };
        num++;
    }
    if (g.ppField[1][2] == EMPTY)
    {
        buf[num] = { 1, 2 };
        num++;
    }
    if (g.ppField[2][1] == EMPTY)
    {
        buf[num] = { 2, 1 };
        num++;
    }
    if (num > 0)
    {
        const size_t index = rand() % num;
        return buf[index];
    }
}

inline void congrats(const TGame& g)
{
    if (g.progress == WON_HUMAN)
        cout << "Human won!" << endl;
    else if (g.progress == WON_AI)
        cout << "Computer won!" << endl;
    else if (g.progress == DRAW)
        cout << "DRAW!" << endl;
}

int main()
{
    TGame g;
    initGame(g);
    clearScr();
    printGame(g);
    do {
        if (g.turn % 2 == 0)
        {
            TCoord c = getHumanCoord(g); //человек
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {  
            TCoord c = getAICoord(g); // компьютер
            g.ppField[c.y][c.x] = g.ai;
        }
        clearScr();
        printGame(g);
        g.turn++;
        g.progress = getWon(g);
    } while (g.progress == IN_PROGRESS);
    //std::cout << "Hello World!\n";
    congrats(g);
    deinitGame(g);
}

