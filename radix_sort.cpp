
/**
 * Radix Sorting 
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void RadixSort(vector<int> & list);
void CountingSort(vector<int> & list, int max, int min, int divisor);
int maxElement(vector<int> list);
void GenerateArray(vector<int> &list, int amount);
void RunTest();


int main()
{
    RunTest();

    // vector<int> list;
    // GenerateArray(list, 1500000);

    // int max = *max_element(list.begin(), list.end());
    // int min = *min_element(list.begin(), list.end());

    // cout << "Before sort : ";
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << list[i] << " ";
    // }

    // cout << endl;

    // RadixSort(list);

    // cout << "After sort : ";
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << list[i] << " ";
    // }

    // cout << endl;
    // return 0;
}



void RadixSort(vector<int> & list)
{
    int maxEle = maxElement(list);
    
    int max = *max_element(list.begin(), list.end());
    int min = *min_element(list.begin(), list.end());
        

    for (int i = 1; (maxEle / i) > 0; i *= 10)
    {
        CountingSort(list, max, min, i);
    }
} 
int maxElement(vector<int> list)
{
    int max = list[0];
    int size = list.size();

    for (int i = 1; i < size; i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }

    return max;
}

void CountingSort(vector<int> & list, int max, int min, int divisor)
{
    int size = list.size();
    vector<int> listC((max - min +1));
    vector<int> listB(size);

    //count all elements in arr
    for (int i = 0; i < size; i++)
    {
        ++listC[(list[i] / divisor) % 10];
    }


    int cSize = listC.size();

    for (int i = 1; i < cSize; i++)
    {
        listC[i] = listC[i] + listC[i - 1];
    }

    //placing arr elements into the output arrayC in the right position
    for (int i = size - 1; i >= 0; i--)
    {
        listB[listC[(list[i] / divisor) % 10] - 1] = list[i];
        listC[(list[i] / divisor) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        list[i] = listB[i];
    }
}


void RunTest()
{
    
    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/radix_sort.txt");

    int x = 0, count =1;
    cout << "Starting Test" << endl;
    
    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        vector<int> list;
        GenerateArray(list, x);

        auto start = high_resolution_clock::now();
        RadixSort(list);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        resultFile << "x = " <<x <<" y = "
         << duration.count() << "" << endl; 
         count++;
    }

    resultFile.close();

    testFile.close();

    cout << "Test complete " <<endl;
}


void GenerateArray(vector<int> &list, int amount)
{
    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++)
    {
        list.push_back((rand() % 100) + 1);
    }
}