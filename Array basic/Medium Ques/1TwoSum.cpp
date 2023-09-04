#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if(mp.find(target-nums[i]) != mp.end()){
            res.emplace_back(i);
            res.emplace_back(mp[target-nums[i]]);
            return res;
        }
        mp[nums[i]] = i;
    }
    
}

// Using Hashing to solve this type of problem
// Time c = O(n);
// space c = O(n);

int main(){
     vector<int> vec;
     vector<int> ans;
     int n;
     cin>>n;
     for (int i = 0; i < n; i++)
     {
        int x;
        cin>>x;
        vec.push_back(x);
     }
     ans = twoSum(vec,target);
     for(auto it: ans){
        cout<<it<<" ";
     }
return 0;
}