#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution{
    public:
        vector<int> maxSlidingWindow(vector<int> &vec,int k){
            deque<int> dq;
            vector<int> ans;
            for (int i = 0; i < vec.size(); i++)
            {
               if(!dq.empty() && dq.front() == i-k) dq.pop_front();

               while(!dq.empty() && vec[dq.back()] < vec[i]) dq.pop_back();

               dq.push_back(i);
               if(i>=k-1) ans.push_back(vec[dq.front()]);
            }
           return ans; 
        }
};


int main(){
 Solution a;
 vector<int> ans;
 vector<int> vec;
 int n = 5;
 for (int i = 0; i < 5; i++)
 {
    int x;
    cin>>x;
    vec.push_back(x);
 }
 ans = a.maxSlidingWindow(vec,3);
  for(auto it: ans){
    cout<<it<<" ";
  }
return 0;
}