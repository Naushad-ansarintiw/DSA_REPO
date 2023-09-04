#include <iostream>
using namespace std;

void merge(int * arra ,int s,int e){
    int temp;
    for (int i = 0; i < e; i++)
    {
        int min = i;
        for (int j = i+1; j <=e; j  ++)
        {
            if(arra[min] > arra[j]) min = j;
        }
        temp =arra[min];
        arra[min] = arra[i];
        arra[i] = temp;
    }
    
}

void mergeSort(int *arry, int s, int e)
{
    if (s == e)
    {
        return;
    }

    int mid = (s + e) / 2;
    // Left part sort karna hai
    mergeSort(arry, s, mid);

    // right part sort karna hai
    mergeSort(arry, mid + 1, e);

    merge(arry, s, e);
}
int main()
{
    int arr[] = {12,4,3,76};
    int n = 4;
    mergeSort(arr, 0, n - 1);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}