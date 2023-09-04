/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
vector<int> prime(100001, 0);
void sieve(int n){
    // cout<<n<<endl;
    for(int i=2; i*i<=100000; i++){
        // cout<<i<<" ";
        if(prime[i] == 0){
            for(int j=i*i; j<=100000; j+=i){
                prime[j] = 1;
            }
        }
    }
}

string solve(string S){
    int n = S.size();
    map<char,int> mpp;
    for(int i=0; i<n; i++){
        mpp[S[i]]++;
    }
    string newStr = "";
    for(int i=0;i<n; i++){
        int val = mpp[S[i]];
        if(val == 1) newStr += S[i];
        else {
            if(prime[val] == 1) newStr += S[i];
        }
    }
    
    if(newStr.size() == 0) return "MARRY";
    return newStr;
    
}

int main()
{
    int t;
    cin>>t;
    // cout<<"HEL"<<endl;
    sieve(100001);
    // cout<<"D"<<endl;
    while(t--){
        string a;
        cin>>a;
        cout<<solve(a)<<endl;
    }
    return 0;
}
