#include <bits/stdc++.h>
#define ll long long int
using namespace std;
static bool comparator(pair<pair<ll, ll>, int > a, pair<pair<ll, ll>, int > b){
    if(a.first.first == b.first.first && a.first.second == b.first.second){
        // cout<<a.second<<" "<<b.second<<endl;
        if(a.second == 0 || b.second == 0) return false;
    }

    if(a.first.first > b.first.first) return true;
    else if(a.first.first == b.first.first && a.first.second > b.first.second) return true;
    else return false;
}

int main(){
     int t;
     cin>>t;
     while(t--){
        int n, m, h;
        cin>>n>>m>>h;

        vector<vector<int>> vec(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            vector<int> temp(m, 0);
            for(int j=0; j<m; j++){
                cin>>temp[j];
            }
            vec[i] = temp;
        }

        for (auto& it : vec) {
            sort(it.begin(), it.end());
        }
        
        vector<pair<pair<ll, ll>, int >> ans;

        vector<pair<ll, ll>> position(m, {0,0});

        for(int i=0; i<n; i++){
            int hours = h;
           ll point=0, penalty = 0, prevpenalty = 0;
            for(int j=0; j<m; j++){
                if(hours>=vec[i][j]){
                    point += 1;
                    penalty = vec[i][j] + 2*prevpenalty;
                    prevpenalty += vec[i][j];
                }
                else break;
                hours -= vec[i][j];
            }
            ans.push_back({{point, penalty}, i});
        }

        sort(ans.begin(), ans.end(), comparator);

        int time = 0;
        for(auto it: ans){
            if(it.second == 0) break;
            time+=1;
        }
        cout<<time+1<<endl;
     }
return 0;
}