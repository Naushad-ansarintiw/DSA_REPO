#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, k, h;
        cin>>n>>m>>k>>h;

        vector<int> vec(n, 0);
        for(int i=0; i<n; i++) {
            int x;
            cin>>x;
            vec.push_back(abs(x-h));
        }

        if(m == 1) cout<<0<<endl;
        else {
            int cnt = 0;
            set<int> st;
            for(int i=0; i<m-1; i++) {
                st.insert(k*(i+1));
            }
            for(auto it: vec) {
                if(st.find(it) != st.end()) {
                    cnt+=1;
                }
            }
            cout<<cnt<<endl;
        }  
    }   
    return 0;
}