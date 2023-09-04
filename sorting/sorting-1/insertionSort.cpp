#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr,int n){
    for (int i = 1; i < n; i++)
    {
       int temp = arr[i];
       int j = i-1;
       for (;j>= 0 ;j--)
       {
        if(arr[j]>temp){ 
            // shift
            arr[j+1] = arr[j];
         }
         else {
            break;
         }
       }
       arr[j+1] = temp;
    }   
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    insertionSort(vec, n);
    for (auto it : vec)
    {
        cout << it << " ";
    }
    return 0;
}