
/**
 * Radix Sorting 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void RadixSort(int arr[], int size);
void CountingSort(int arr[], int size, int range);
int getMax(int arr[], int size);

int main(){

    int arr [] = {9,3,1,5,3};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
  
    RadixSort(arr, len);

    cout << "After sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

void RadixSort(int arr[], int size){
    int max = getMax(arr, size);
    
    for(int i = 1; (max/i) > 0; i*=10){
       CountingSort(arr, size, i);
    }

}

int getMax(int arr[], int size){
    int max = arr[0];
    
    for(int i = 1; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void CountingSort(int arr[], int size, int d){
    int arrayB[size];
    int arrayC[10] = {0};

    //count all elements in arr
    for(int i = 0; i < size; i++){
        ++arrayC[(arr[i]/d)%10];
    }

    for(int i = 1; i < 10; i++){
        arrayC[i]= arrayC[i] + arrayC[i-1];
    }

    //placing arr elements into the output arrayC in the right position
    for(int i = size -1 ; i >= 0; i--){
        arrayB[arrayC[(arr[i]/d)%10]-1]= arr[i];
        arrayC[(arr[i]/d)%10]--;
    }

     for(int i = 0; i < size; i++){
       arr[i]= arrayB[i];
    }
}