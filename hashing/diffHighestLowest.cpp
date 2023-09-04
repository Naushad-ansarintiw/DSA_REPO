#include <iostream>
using namespace std;

bool isVisited(bool array[], int index)
{
    if (array[index] == true)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {5,6,43,7,3,2,2,1,3,5};
    int n = 10,maxi = 1,count = 1;
    int min = n;
    bool visitedArray[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!isVisited(visitedArray, i)){
            visitedArray[i] = true;
            for (int j = 1; j < n; j++)
            {
                if(arr[i] == arr[j]) {count++; visitedArray[j] = true;}
            }
            if(count>maxi) maxi = count;
            if(count<min) min = count;
        }
        count = 0;
    }
    cout<<maxi - min;
    return 0;
}