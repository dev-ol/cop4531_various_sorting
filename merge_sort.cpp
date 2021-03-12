
/**
 * merge Sorting 
 * https://simplesnippets.tech/merge-sort-algorithm-with-example-with-c-code-sorting-algorithms-data-structures/
*/

#include <iostream>
using namespace std;

void sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){
    int myarr [] = {9,3,1,5,2};

    int len = sizeof(myarr) / sizeof(myarr[0]);

    cout << "Before sort : ";
    for(int i = 0; i < len; i++){
        cout << myarr[i] << " ";
    }

    cout << endl;

    sort(myarr, 0, len-1);
    
    cout << "After sort : ";
    for(int i = 0; i < len; i++){
        cout << myarr[i] << " ";
    }

    cout << endl;
    return 0;
}

//merge sort function
void sort(int arr[], int l, int r){

    if(l<r){
        int m = (l+r)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr, l, m, r);

    }
}

void merge(int arr[], int l, int m, int r){
    //starting index for left subarray
    int i = l; 

    // right subarray starting index
    int j = m + 1;

    //temp starting index 
    int k = l;

   
    int temp[5];

    while(i<=m && j<=r){

        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=m){
        
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=r){
        
        temp[k] = arr[j];
        j++;
        k++;
    }

 
    for(int p = l; p <= r; p++){
        arr[p] = temp[p];
    } 
}
