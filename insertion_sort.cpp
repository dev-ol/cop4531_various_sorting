
/**
 * Insertion InsertionSorting 
*/
#include <chrono> 
#include <iostream>
#include <ctime> 
using namespace std;
using namespace std::chrono; 

void InsertionSort(int arr[], int len);
void GenerateArray(int arr[], int amount);

int main(){
    int arr [100000];

    GenerateArray(arr, 100000);

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before InsertionSort : ";
    for(int i = 0; i < len/2; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    auto start = high_resolution_clock::now(); 
    InsertionSort(arr, len);
    auto stop = high_resolution_clock::now(); 

     cout << "After InsertionSort : ";
    for(int i = 0; i < len/2; i++){
        cout << arr[i] << ",";
    }

    cout << endl;

     auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}

void InsertionSort(int arr[],int len){

    int key;
    int j = 0;
    
    for(int i = 1; i< len; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > key){

            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}

void GenerateArray(int array[], int amount){
  
 srand((unsigned)time(0)); 
     
    for(int i=0; i<amount; i++){ 
        array[i] = (rand()%100)+1; 
        //cout << array[i] << endl;
 } 
}