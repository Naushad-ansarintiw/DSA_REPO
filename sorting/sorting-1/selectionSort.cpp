#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[minIndex], arr[i]);
    }
}
int main()
{
    vector<int> vec;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    
    selectionSort(vec,n);
    for(auto it: vec){
        cout<<it<<" ";
    }
    return 0;
}