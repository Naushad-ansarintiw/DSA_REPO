#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & vec,int target){
    int l=0;
    int h = (vec.size() * vec[0].size()) - 1;
    while (l<=h)
    {
        int mid = (l+h)/2;
       if(vec[mid/vec[0].size()][(mid%vec[0].size())] == target) return true;
       else if(vec[mid/vec[0].size()][(mid%vec[0].size())] < target)  l = mid+1;
       else h = mid - 1;
    }
   return false;   
}

int main(){

     vector<vector<int>> vec = {{1,3,5,7},
                               {10,11,16,20},
                               {23,30,34,60}};
     if (searchMatrix(vec,16))
     {
        cout<<"Yes"<<endl;
     }
     else{
        cout<<"no"<<endl;
     }
     
     
return 0;
}