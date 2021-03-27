
/**
 * Counting Sorting 
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void CountingSort(vector<int> &list, int max, int min);
void GenerateArray(vector<int> &list, int amount);
void RunTest();

int main()
{

    RunTest();

    return 0;
}

void CountingSort(vector<int> &list, int max, int min)
{

    int size = list.size();
    vector<int> listC((max - min + 1));
    vector<int> listB(size);

    //count all elements in arr
    for (int i = 0; i < size; i++)
    {
        ++listC[list[i] - min];
    }

    int cSize = listC.size();

    for (int i = 1; i < cSize; i++)
    {
        listC[i] = listC[i] + listC[i - 1];
    }

    //placing arr elements into the output arrayC in the right position
    for (int i = 0; i < size; i++)
    {
        listB[listC[list[i] - min] - 1] = list[i];
        --listC[list[i] - min];
    }

    for (int i = 0; i < size; i++)
    {
        list[i] = listB[i];
    }
}

void RunTest()
{

    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/counting_sort.txt");

    int x = 0, count = 1;
    cout << "Starting Test" << endl;

    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        vector<int> list;
        GenerateArray(list, x);

        int max = *max_element(list.begin(), list.end());
        int min = *min_element(list.begin(), list.end());

        auto start = high_resolution_clock::now();
        CountingSort(list, max, min);

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