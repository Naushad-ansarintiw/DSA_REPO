// NOt Done Solve this 

#include <iostream>
#include <vector> 

using namespace std;

class Solution {
private: 
    void solve(vector<int>& nums, int index , vector<vector<int>>& ans){
        // base case
        if(index >= nums.size()){
            ans.push_back(nums);
            
            return ;
        }

        // solving one case 

        for(int i = index ; i<nums.size();i++){
            // cout<<"hello"<<endl;
                
                swap(nums[i],nums[index]);
                solve(nums,index+1,ans);
                // Backtraking
                swap(nums[i],nums[index]);
                
                 for(int j = index+1 ; j<nums.size(); j++){
                  if(nums[index] != nums[j]){
                      swap(nums[index],nums[j]);
                      int t = index;
                      index = j;
                      solve(nums,index+1,ans);
                      swap(nums[t],nums[j]);
                      i = j -1;
                      break;
                  }
              }
              

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // cout<<"Hello"<<endl;
        vector<vector<int>> ans;
        //   cout<<"Hello"<<endl;
        int index = 0;
        solve(nums,index,ans);
        for(auto it: ans){
            for(auto ptr: it){
                cout<<ptr++;
            }
            cout<<endl;
        }
        return ans;
    }
};

int main()
{
   Solution a;
   vector<int> vec;
   vec.push_back(1);
    vec.push_back(2);
     vec.push_back(3);
   a.permuteUnique(vec);

    return 0;
}