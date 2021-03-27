
/**
 * Insertion InsertionSorting 
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void InsertionSort(vector<int> &list);
void GenerateArray(vector<int> &list, int amount);
void RunTest();

int main()
{
    RunTest();
    return 0;
}

void InsertionSort(vector<int> &list)
{

    int key;
    int j = 0;
    int size = list.size();

    for (int i = 1; i < size; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > key)
        {

            list[j + 1] = list[j];
            j = j - 1;
        }

        list[j + 1] = key;
    }
}

void RunTest()
{

    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/insertion_sort.txt");

    int x = 0, count = 1;
    cout << "Starting Test" << endl;

    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        vector<int> list;
        GenerateArray(list, x);

        auto start = high_resolution_clock::now();

        InsertionSort(list);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        resultFile << "x = " << x << " y = "
                   << duration.count() << "" << endl;
        count++;
    }

    resultFile.close();

    testFile.close();

    cout << "Test complete " << endl;
}

void GenerateArray(vector<int> &list, int amount)
{
    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++)
    {
        list.push_back((rand() % 100) + 1);
    }
}