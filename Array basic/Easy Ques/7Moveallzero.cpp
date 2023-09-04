#include <iostream>
using namespace std;
int main(){
     int arr[] = {0,0,0,0,1,2,0,0,0,4};
     int n = 10;
     int i = 0;
     int j = 1;
     while(i<n && j<n){
        if(arr[i] != 0 && arr[j] != 0) {
            i++; j++;
        }
        else if(arr[i] == 0 && arr[j] == 0) j++;
        else if(arr[i] == 0 && arr[j] != 0) {
            swap(arr[i],arr[j]);
            i++; j++;
        }
        else{
            i++;j++;
        }
     }
     for(auto it: arr) cout<<it<<" ";
return 0;
}