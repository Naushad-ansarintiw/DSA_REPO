#include <iostream>
#include <vector>
using namespace std;

// int subarraySum(int *arr,int k,int n){
//     int sum = 0,count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if(sum == k) count++; 
//         }
//         sum = 0;
//     }
//    return count; 
// }

void subArrSum(int index,int sum,int *count,int k,vector<int> &arr,vector<int> &ds){
    if(index>=arr.size()) return;
     cout<<"j"<<" ";
    for (int i = index; i < arr.size(); i++)
    {
       if(ds.size() == i || index == 0) {
       
        sum += arr[i];
        if(k == sum) *count++;
        ds.push_back(arr[i]);
        subArrSum(index+1,sum,count,k,arr,ds);
        sum -= arr[i];
        ds.pop_back();
       }
    }  
}

void subArr(vector<int> &arr,int k){
    vector<int> ds;
    int sum = 0;
    int count = 0;
    subArrSum(0,sum,&count,k,arr,ds);
    cout<<count<<endl;
}
int main(){
     vector<int> arr;
     int n = 3;
     for(int i = 0;i<n;i++){
       int x;
       cin>>x;
       arr.push_back(x);
     }
     int k = 3;
     subArr(arr,k);
return 0;
}