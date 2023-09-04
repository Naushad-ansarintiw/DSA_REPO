#include <iostream>
using namespace std;

int partition(int *arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
       if(pivot >= arr[i]) count++;
    }

    //place pivot at right position
    int pivotIndex = s+count;
    swap(arr[s],arr[pivotIndex]);
    int i = s,j=e;
     while (i<pivotIndex && j>pivotIndex)
     {
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pivotIndex && j>pivotIndex) swap(arr[i++],arr[j--]);
     }
     return pivotIndex;  
}

void quickSort(int *arr,int s,int e){
    // base Case
    if(s>=e) return;
    // Getting partition index
    int p = partition(arr,s,e);
    //Sort Left part
    quickSort(arr,s,p-1);
    //Sort Right part
    quickSort(arr,p+1,e);
}
int main(){
     int arr[] = {2,4,1,6,9};
     int n = 5;
     quickSort(arr,0,n-1);
     for(auto it: arr){
        cout<<it<<" ";
     }
return 0;
}