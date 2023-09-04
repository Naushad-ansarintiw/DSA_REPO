#include <bits/stdc++.h>
using namespace std;

int cnt(int ele, int start, int end, vector<int>&vec) {
    int ans = 0;
    for(int i=start; i<end; i++) {
        if(vec[i] == ele) ans+=1;
    }
    return ans;
}

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }

    int feleCnt = 0, leleCnt = 0;

    feleCnt = cnt(vec[0], 0, n, vec);
    leleCnt = cnt(vec[n-1], 0, n, vec);
    
    if(vec[0] == vec[n-1]) {
        if(feleCnt >= k){
            cout<<"Yes"<<endl;
            return;
        }
        else cout<<"No"<<endl;
    }
    else {
        if(feleCnt >= k && leleCnt >= k) {
            int i=0, j=n-1, t=0, index=0; 
            while(t<k && index < n) {
                if(vec[index] == vec[0]) {
                    t+=1;
                    i=index;
                }
                index+=1;
            }
            index = n-1;
            t=0;
            while(t<k && index >=0) {
                if(vec[index] == vec[n-1]) {
                    t+=1;
                    j=index;
                }
                index-=1;
            }     
            if(i<j) {
                cout<<"Yes"<<endl;
                return ;
            }
            else {
                cout<<"No"<<endl;
                return;
            }
        }
        else {
            cout<<"No"<<endl;
            return;
        }
    }   
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();

    }
     
return 0;
}