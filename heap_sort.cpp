
/**
 * heap Sorting  66815
 * https://www.youtube.com/watch?v=yXluViYl-DM
*/
#include <chrono> 
#include <iostream>
#include <ctime> 
#include <fstream>
using namespace std;
using namespace std::chrono; 

void heapSort(int arr[], int size);
void heapify(int arr[], int size, int i);
void  buildHeap(int arr[], int size);
void RunTest();
void GenerateArray(int arr[], int amount);

int main(){
    RunTest();
    // int myarr [100000];

    // GenerateArray(myarr, 100000);

    // int len = sizeof(myarr) / sizeof(myarr[0]);

    // cout << "Before sort : ";
    // for(int i = 0; i < len/10; i++){
    //     cout << myarr[i] << " ";
    // }

    // cout << endl;

    //  auto start = high_resolution_clock::now(); 
    // heapSort(myarr, len);
    // auto stop = high_resolution_clock::now(); 

    // cout << "After sort : ";
    // for(int i = 0; i < len/10; i++){
    //     cout << myarr[i] << " ";
    // }

    // cout << endl;

    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

    return 0;
}

//merge sort function
void heapSort(int arr[], int size){

  buildHeap(arr, size);

  for(int i = size-1; i>= 0; i--){
      swap(arr[0], arr[i]);
      heapify(arr,i,0);
  }
}

void  buildHeap(int arr[], int size){
    for(int i = (size/2)-1; i>=0; i--){
        heapify(arr, size,i);
    }
}

void heapify(int arr[], int size, int i){
    int left = 2*i + 1;
    int right = 2 * i + 2;

    int large = i;

    if(left < size && arr[left] > arr[i]){
        large = left;
    }

    if(right < size && arr[right] > arr[large]){
        large = right;
    }
    if(large != i){
        swap(arr[i], arr[large]);
        heapify(arr, size, large);
    }

}

void RunTest(){
    ifstream testFile("array_length_tests.txt");
    ofstream resultFile("results/heap_sort.txt");
    
    int x = 0, count =1;
    
     cout << "Starting Test" << endl;
    while(testFile >> x){
        cout << "Test " << count << " : " << x << endl;

        int test_array[x];
        GenerateArray(test_array, x);

        auto start = high_resolution_clock::now(); 
        heapSort(test_array, x);
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

void GenerateArray(int array[], int amount){
  
 srand((unsigned)time(0)); 
     
    for(int i=0; i<amount; i++){ 
        array[i] = (rand()%100)+1; 
        //cout << array[i] << endl;
 } 
}