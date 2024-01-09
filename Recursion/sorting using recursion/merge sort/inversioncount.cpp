#include<iostream>
using namespace std;

int merge(int *arr, int s, int e) {
    int invc=0;
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
            invc=invc+(mid-index1);
            // cout<<invc<<endl;
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete []first;
    delete []second;

    

}

int mergeSort(int *arr, int s, int e) {
    int invc=0;
    int mid = (s+e)/2;
    //base case
    if(s < e) {
        
        
    
    //left part sort karna h 
    invc+=mergeSort(arr, s, mid);
    
    //right part sort karna h 
    invc+=mergeSort(arr, mid+1, e);

    //merge
    invc+=merge(arr, s, e);
        
    }
    
    return invc;

}

int main() {

    int arr[] = {1, 20,6, 4, 5};
    int n = 5;

    int inversioncount =mergeSort(arr, 0, n);

    cout<<inversioncount<<endl;    

    return 0;
}