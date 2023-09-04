#include <iostream>
#include <algorithm>
using namespace std;

void findsecondSmallLargest(int *arr,int n){
     int secondMin = arr[0];
     int secondMax = arr[n-1];
     int i = 0,j=n-1;
     while(i<j){
          if(secondMin<arr[i+1]) {
              secondMin = arr[i+1];
          }
          if(secondMax>arr[j-1]){
            secondMax = arr[j-1];
          }
          if(secondMin>arr[0] && secondMax<arr[n-1]) break;
          if(secondMin==arr[0]) i++;
          if(secondMax==arr[n-1]) j--;
     }
     if(i>j || i==j) {
        cout<<-1<<" "<<-1<<endl;
        return;
     }
   cout<<secondMin<<" "<<secondMax<<endl;
}
int main(){
     int arr[] = {1,4,5,1,4,8,74,3};
     int n = 8;
     sort(arr,arr+n);
     findsecondSmallLargest(arr,n);
return 0;
}