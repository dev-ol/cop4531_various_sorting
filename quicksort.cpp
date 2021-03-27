
/**
 * Quick Sorting 
*/
#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
using namespace std::chrono;

void QuickSort(int arr[], int startIndex, int endIndex);
int Partition(int arr[], int startIndex, int endIndex);
void GenerateArray(int arr[], int amount);
void RunTest();

int main()
{
    RunTest();

    return 0;
}

void QuickSort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int part = Partition(arr, startIndex, endIndex);
        QuickSort(arr, startIndex, (part - 1));
        QuickSort(arr, (part + 1), endIndex);
    }
}

int Partition(int arr[], int startIndex, int endIndex)
{
    int pivot = arr[endIndex];
    int index = startIndex;

    for (int i = startIndex; i < endIndex; i++)
    {

        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

            index++;
        }
    }

    int temp = arr[endIndex];
    arr[endIndex] = arr[index];
    arr[index] = temp;

    return index;
}

void RunTest()
{

    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/quicksort.txt");

    int x = 0, count = 1;
    cout << "Starting Test" << endl;

    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        int test_array[x];
        GenerateArray(test_array, x);

        auto start = high_resolution_clock::now();
        QuickSort(test_array, 0, x - 1);

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

void GenerateArray(int array[], int amount)
{

    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++)
    {
        array[i] = (rand() % 100) + 1;
    }
}