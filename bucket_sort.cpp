
/**
 * Bucket Sorting 
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void BucketSort(vector<int> &list);
void GenerateArray(vector<int> &list, int amount);
void RunTest();

int main()
{
    RunTest();

    return 0;
}

void BucketSort(vector<int> &list)
{
    //buckets
    int size = list.size();
    vector<vector<int>> bucket(size);
    int tempIndex = 0;

    //adding elements to the buckets
    for (int i = 0; i < size; i++)
    {
        int index = 0;

        index = list[i] / 10;
        bucket[index].push_back(list[i]);
    }

    //sorting each bucket
    for (int i = 0; i < size; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    //put elements back into the array
    for (int i = 0; i < size; i++)
    {
        for (int x = 0; x < bucket[i].size(); x++)
        {
            list[tempIndex++] = bucket[i][x];
        }
    }
}

//use to run the test on the algorithms
void RunTest()
{
    //use this file to store the lengths of array to test
    ifstream testFile("array_length_tests.txt");
    //file where I store the results of the sort
    ofstream resultFile("results/bucket_sort.txt");

    int x = 0, count = 1;
    cout << "Starting Test" << endl;

    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        vector<int> list;
        //generating random elements for the list
        GenerateArray(list, x);

        //timer to keep track of the time
        auto start = high_resolution_clock::now();
        BucketSort(list);

        auto stop = high_resolution_clock::now();

        //calculating the time
        auto duration = duration_cast<microseconds>(stop - start);

        //storing the time and number of elemenrs as x and y values
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