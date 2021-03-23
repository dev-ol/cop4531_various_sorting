
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

void BucketSort(vector<int> & list);
void GenerateArray(vector<int> & list, int amount);
void RunTest();

// struct Buckets{
//     int bucket[]
// }
int main(){
    RunTest();
   
    // vector<int> list;
    // GenerateArray(list, 100);

//     //cout << arr[1] <<endl;
//     //int len = sizeof(arr) / sizeof(arr[0]);
    
//     cout << "Before sort : ";
//     for(int i = 0; i < 100 ;i++){
//        cout << list[i] << " ";
//     }

//     cout << endl;
  
//    BucketSort(list);

//     cout << "After sort : ";
//     for(int i = 0; i < 100; i++){
//         cout << list[i] << " ";
//     }

//     cout << endl;
    return 0;
}

void BucketSort(vector<int> & list){
    //buckets
    int size = list.size();
    vector<vector<int>> bucket (size); 
    int tempIndex = 0;
    
    //filling bucket with elements
    for(int i = 0; i < size; i++){
        int index = 0;
        
        index = list[i]/10;
     
       //cout << index <<endl;
      bucket[index].push_back(list[i]);
    }

    //sort the single buckets themselves
    for(int i = 0; i < size; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }   
   
    //place elements back in arr
    for(int i = 0; i < size; i++){
       for(int x=0; x< bucket[i].size(); x++){
          list[tempIndex++] = bucket[i][x];
       }
    }

}

void RunTest()
{
    
    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/bucket_sort.txt");

    int x = 0, count =1;
    cout << "Starting Test" << endl;
    
    while (testFile >> x)
    {
        cout << "Test " << count << " : " << x << endl;

        vector<int> list;
        GenerateArray(list, x);

        auto start = high_resolution_clock::now();
        BucketSort(list);

        
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


void GenerateArray(vector<int> & list, int amount)
{
    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++)
    {
        
        list.push_back((rand() % 100) + 1);
    }

}