#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr,int n){
    for (int i = 0; i < n-1; i++)
    {
       for (int j = 0; j < n-i-1; j++)
       {
         if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
       }
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

    bubbleSort(vec, n);
    for (auto it : vec)
    {
        cout << it << " ";
    }
    return 0;
}