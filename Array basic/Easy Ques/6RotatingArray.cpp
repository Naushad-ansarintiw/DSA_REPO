#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int *arr,int s,int e){
    int mid = (s+e)/2;
    int t = 0;
    for (int i = s; i <= mid; i++)
    {
        swap(arr[i],arr[e-t]);
        t++;
    }
    
}

void Rotate(int *arr,int n,int k){
       // reverse first n-k element
       reverse(arr,0,n-k-1);
       // reverse last k elemnt
       reverse(arr,n-k,n-1);

       reverse(arr,0,n-1);
}
int main(){
     int arr[] = {1,2,3,4,5,6,7,8,9,10};
     int n = 10,k=4;
     Rotate(arr,n,k);
     for (auto it: arr)
     {
        cout<<it<<" ";
     }
return 0;
}