// Question name Power set It will also solve using recursion 


#include <iostream>

using namespace std;


vector<string> AllPossibleStrings(string s){
    int n = s.length();
    vector<string> ans;
    string output = "";
    
    // (1<<n)-1 is nothing but 2^n-1
    for(int i = 0 ; i<=(1<<n) - 1 ; i++){
        for(int j = 0 ;j<n;j++){
            if((i & (1<<j)) != 0){
               output += s[j]; 
            }
        }
        
        if(output.length()>0){
            ans.push_back(output);
            output="";
        }
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    
   	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	} 
	
    return 0;
}
