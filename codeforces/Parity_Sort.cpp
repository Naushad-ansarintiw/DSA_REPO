#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solve() {
        ll n;
        cin>>n;
        multiset<ll> mst;
        vector<ll> vec;

        for(int i=0; i<n; i++) {
            ll x;
            cin>>x;
            vec.push_back(x);
            mst.insert(x);
        }
        for(auto it: vec){
            auto itr = mst.begin();
            // cout<<it<<" "<<*itr<<endl;
            if((it&1) && !(*itr&1)) {
                cout<<"NO"<<endl;
                return;
            }

            if(!(it&1) && (*itr&1)){
                cout<<"NO"<<endl;
                return;          
            }
            mst.erase(itr);
        }
        cout<<"Yes"<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}