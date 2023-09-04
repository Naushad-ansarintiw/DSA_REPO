#include <iostream>
using namespace std;

void recursiveSelectionSort(int *arr,int sortedlastIndex,int n){
    if(sortedlastIndex == n-1) return;
    int checkElement = arr[sortedlastIndex+1];
    for (int i=sortedlastIndex; i>=0; i--)
    {
        if(checkElement < arr[i]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    recursiveSelectionSort(arr,sortedlastIndex+1,n);
}
int main(){
     int arr[] = {7,1,23,4,19};
     int n = 5;
     recursiveSelectionSort(arr,0,n);
     for(auto it: arr){
        cout<<it<<" ";
     }
return 0;
}