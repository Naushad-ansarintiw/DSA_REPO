#include <iostream>
#include <vector>
using namespace std;

// Find the maximum subarray sum
class Solution {
    public: 
        int maxSubArray(vector<int> &vec){
            int sum = 0,maxi = INT_MIN;
            for(auto it: vec){
                sum += it;
                maxi = max(sum,maxi);
                if(sum<0) sum = 0;
            }
            return maxi;
        }
};

int main(){
     Solution a;
     vector<int> vec;
     int n = 8;
     for(int i = 0;i<n;i++) {
        int x;
        cin>>x;
        vec.push_back(x);
     }
     cout<<a.maxSubArray(vec);
return 0;
}