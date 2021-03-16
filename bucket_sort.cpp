
/**
 * Counting Sorting 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BucketSort(int arr[], int size);

int main(){

    int arr [] = {9,3,1,5,3};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "start here" << endl;
    BucketSort(arr, len);

    cout << "After sort : ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

void BucketSort(int arr[], int size){
    //buckets
    vector<int> bucket[size];
    int tempIndex = 0;
    
    //filling bucket with elements
    for(int i = 0; i < size; i++){
        int index = 0;
        if(arr[i] < 0){
            index = size * arr[i];
        }else{
            index = (size * arr[i]) / 10;
        }
    
        bucket[index].push_back(arr[i]);
    }

    //sort the single buckets themselves
    for(int i = 0; i < size; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }   
    cout << "after here" << endl;
    //place elements back in arr
    for(int i = 0; i < size; i++){
        for(int x=0; x< bucket[i].size(); x++){
            arr[tempIndex++] = bucket[i][x];
        }
    }

}