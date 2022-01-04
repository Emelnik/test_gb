// lesson6.cpp 

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
int* ptrArr;
int** ptrArr2;
int n;

//Task1
bool FillArr()
{
    std::cout << "\n Enter Array size: ";
    std::cin >> n;
    if (n > 0)
    { 
        ptrArr = new (nothrow) int[n];
        std::cout << "ptrArr: " << ptrArr;
        if (ptrArr != nullptr)
        {
            ptrArr[0] = 1;
            for (size_t i = 0; i < n; i++)
            {
                ptrArr[i + 1] = 2 * ptrArr[i];
            }
            return true;
        }
        else
        {
            std::cout << "Error! Can't allocate memory!";
            return false;
        }
    }
    else
    {
        std::cout << "Error! Zero size!";
        return false;
    }
        
}

void PrintArr(int* pA, int k)
{
    std::cout << "\n Array content: ";
    for (size_t i = 0; i < k; i++)
    {
        std::cout << "\t" << pA[i];
    }
}

//Task2
void init2dim()
{
    srand(time(NULL));
    const size_t m = 4;
    const size_t n = 4;
    ptrArr2 = new int* [m];
    for (size_t i = 0; i < m; i++)
    {
        ptrArr2[i] = new int[n];
    }
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ptrArr2[i][j] = rand() % 1000;
        }
    }
}

void print2dim(int** pA, int m, int n)
{
    std::cout << "\n Matix content: \n";
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cout << ptrArr2[i][j] << "\t";
        }
        std::cout << "\n";
    }
    for (size_t i = 0; i < m; i++) {
    delete[] ptrArr2[i];
    }
    delete[] ptrArr2; 
    ptrArr2 = nullptr;
}


//Task4
void MergeFile(char fn1[], char fn2[])
{
    char filename3[33];
    std::cout << "\n Enter filename for merge: \n";
    std::cin >> filename3;
    ofstream MergeFile(filename3);
    
    ifstream fin1(fn1);
    if (fin1.is_open())
    {
        string buf;
        while (!fin1.eof())
        {
          getline(fin1, buf);
          MergeFile << buf << endl;
        }
        fin1.close();
    }
    ifstream fin2(fn2);
    if (fin2.is_open())
    {
        string buf;
        while (!fin2.eof())
        {
          getline(fin2, buf);
          MergeFile << buf << endl;
        }
        fin2.close();
    }
}

//Task5
bool FindWord(char fn[], char word[])
{
    ifstream ScanFile(fn);
    if (ScanFile.is_open())
    {
        int count(0);
        string line;
        while (getline(ScanFile, line))
        {
            if (line.find(word) != string::npos)
                count++;
        }
        if (count)
        {
            std::cout << word << " was found in " << fn << std::endl;
            return true;
        }
        else
        {
            std::cout << "not found";
            return false;
        }
    }
}
 
int main()
{
    std::cout << "\n \n Task 1";
    if (FillArr())
    {
       PrintArr(ptrArr, n);
       delete[] ptrArr;
       ptrArr = nullptr;
    }
  
    std::cout << "\n \n Task 2";
    init2dim();
    print2dim(ptrArr2, 4, 4);

    std::cout << "\n \n Task 3";
    char filename1[33];
    char filename2[33];
    cout << "\n Enter name file 1 \n";
    cin >> filename1;
    cout << "Enter name file 2 \n";
    cin >> filename2;
    ofstream Fileout1(filename1);
    Fileout1 << "File with name " << filename1 << " created. \n This is a content of file 1: \n Some text.." << endl;
    Fileout1.close();
    ofstream Fileout2(filename2);
    Fileout2 << "File with name " << filename2 << " created. \n This is a content of file 2: \n Some text.." << endl;
    Fileout2.close();
    
    std::cout << "\n \n Task 4";
    MergeFile(filename1, filename2);
   
    std::cout << "\n \n Task 5";
    char Fword[20];
    cout << "\nEnter word to fiend in file: " << filename1 << "\n";
    cin >> Fword;
    FindWord(filename1, Fword);

   cin.get();
   return 0;
}
