#include <iostream>
using namespace std;

void merge(int *arr,int s,int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // cooy value 
    int mainarrayIndex =s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainarrayIndex++];
    }
    
    mainarrayIndex =mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainarrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainarrayIndex = s;
    while(index1<len1 && index2<len2){
        if (first[index1]<second[index2])
        {
            arr[mainarrayIndex++] = first[index1++];
        }
        else{
          arr[mainarrayIndex++] = second[index2++];

        }   
    }
    

    while(index1<len1){
        arr[mainarrayIndex++] = first[index1++];
    }
    while(index2<len2){
        arr[mainarrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}


void mergeSort(int *arry,int s,int e){
    //base case
    if(s>=e){
        return;
    }
    
    int mid = (s+e)/2;
    // Left part sort karna hai 
    mergeSort(arry,s,mid);

    // right part sort karna hai
    mergeSort(arry,mid+1,e);

    merge(arry,s,e);
}


int main(){
     int arr[7] = {2,3,4,1,8,5,4};
     int n = 7;

     mergeSort(arr,0,n-1);

     for(auto it: arr){
        cout<<it<<" ";
     }
return 0;
}