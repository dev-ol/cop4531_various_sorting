
/**
 * Insertion Sorting 
*/

#include <iostream>
using namespace std;

void sort(int arr[]);

int main(){
    int arr [] = {9,3,1,5,3};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    sort(arr);
     cout << "After sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

void sort(int arr[]){

    int key;
    int j = 0;

    for(int i = 1; i< 5; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > key){

            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}