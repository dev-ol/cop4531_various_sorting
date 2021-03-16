
/**
 * Counting Sorting 
*/

#include <iostream>
using namespace std;

void QuickSort(int arr[], int size, int range);

int main(){
    int size = 5;
    int range = 10;

    int arr [size] = {9,3,1,5,3};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    CountingSort(arr, size, range);

    cout << "After sort : ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

void QuickSort(int arr[], int size, int range){
    int arrayB[size];
    int arrayC[range];

    //set all element to zero
    for(int i = 0; i < range; i++){
        arrayC[i]=0;
    }

    //count all elements in arr
    for(int i = 0; i < size; i++){
        ++arrayC[arr[i]];
    }

    for(int i = 1; i < range; i++){
        arrayC[i]= arrayC[i] + arrayC[i-1];
    }

    //placing arr elements into the output arrayC in the right position
    for(int i = 0; i < size; i++){
        arrayB[--arrayC[arr[i]]]= arr[i];
    }

     for(int i = 0; i < size; i++){
       arr[i]= arrayB[i];
    }
}