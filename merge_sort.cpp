
/**
 * merge Sorting 
 * https://simplesnippets.tech/merge-sort-algorithm-with-example-with-c-code-sorting-algorithms-data-structures/
*/

#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
using namespace std::chrono;

void sort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void GenerateArray(int *array, int amount);
void RunTest();

int main()
{
    RunTest();
    return 0;
}

//merge sort function
void sort(int *arr, int l, int r)
{

    if (l < r)
    {
        // cout<<"ruuuun" <<endl;
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        sort(arr, l, m);
        sort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void RunTest()
{

    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/merge_sort.txt");

    int x = 0, count = 1;
    cout << "Starting Test" << endl;

    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        int test_array[x];
        GenerateArray(test_array, x);

        auto start = high_resolution_clock::now();
        sort(test_array, 0, x - 1);

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

void GenerateArray(int *array, int amount)
{

    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++)
    {
        array[i] = (rand() % 100) + 1;
    }
}