
/**
 * heap Sorting 
 * https://www.youtube.com/watch?v=yXluViYl-DM
*/

#include <iostream>
using namespace std;

void heapSort(int arr[], int size);
void heapify(int arr[], int size, int i);

void  buildHeap(int arr[], int size);

int main(){
    int myarr [] = {9,3,1,5,2};

    int len = sizeof(myarr) / sizeof(myarr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << myarr[i] << " ";
    }

    cout << endl;

    heapSort(myarr, len);
    
    cout << "After sort : ";
    for(int i = 0; i < len; i++){
        cout << myarr[i] << " ";
    }

    cout << endl;
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