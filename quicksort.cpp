
/**
 * Quick Sorting 
*/

#include <iostream>
using namespace std;

void QuickSort(int arr[], int startIndex, int endIndex);
int Partition(int arr[], int startIndex, int endIndex);

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

    QuickSort(arr, 0, len);

    cout << "After sort : ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

void QuickSort(int arr[], int startIndex, int endIndex){
   if(startIndex< endIndex){
       int part = Partition(arr,startIndex, endIndex);
       QuickSort(arr, startIndex, (part-1));
       QuickSort(arr, (part+1), endIndex);

   }
}

int Partition(int arr[], int startIndex, int endIndex){
    int pivot = arr[endIndex];
    int index = startIndex;

    for(int i = startIndex; i < endIndex; i++){

        if(arr[i] < pivot){
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