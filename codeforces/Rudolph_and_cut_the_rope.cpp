#include <bits/stdc++.h>
using namespace std;

static bool comparator(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
int main(){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;
            vec.push_back({x,y});
        }

        sort(vec.begin(),vec.end(), comparator);
        int minRopes = 0;
        for(auto it: vec){
            if(it.first > it.second){
                minRopes+=1;
            }
        }
        cout<<minRopes<<endl;
     }
return 0;
}