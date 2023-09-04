// T.C O(n)
// S.C O(n)

#include <iostream>
#include <stack>
using namespace std;
int main(){
     string str="naushad";

     stack<char> s;
     for(int i=0;i<str.length();i++){
        char c = str[i];
        s.push(c);
     }

     string ans = "";

     while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
     }

     cout<<"answer is "<<ans<<endl;
return 0;
}