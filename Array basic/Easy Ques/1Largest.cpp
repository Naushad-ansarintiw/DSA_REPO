#include <iostream>
using namespace std;
int main(){
     int arr[] = {1,3,7,4,2,2323,3243,443};
     int n = 8;
     int max = 0;
     for (int i = 1; i < n; i++)
     {
       if(arr[max]< arr[i]) max = i;
     }
     cout<<arr[max];
return 0;
}

