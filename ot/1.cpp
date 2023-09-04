#include<bits/stdc++.h>
using namespace std;

int mazeObstaclesUtil(vector<vector<int>>& maze, pair<int,int> source, pair<int,int> destination, int N, int M) {
    if(source.first==destination.first && source.second==destination.second) return 0; 
    queue<pair<int, pair<int,int>>> q;
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(int i=0; i<4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(newr >= 0 && newr < N && newc >=0 && newc < M && maze[newr][newc] == 1 && dis+1 < dist[newr][newc]) {
                dist[newr][newc] = 1 + dis;
                if(newr == destination.first && newc == destination.second) {
                    return 1+dis;
                }
                q.push({1+dis, {newr, newc}});
            }
        }
    }
    return -1;
}

int solution(int N, int M, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2) {
    // Implement your solution here
     vector<vector<int>> maze(N, vector<int>(M, 1));

     int sz = X1.size();
     for(int i=0; i<sz; i++) {
        int x1 = X1[i];
        int y1 = Y1[i];
        int x2 = X2[i]; 
        int y2 = Y2[i];

        if(x1 == x2 && y1 == y2) {
            maze[x1][y1] = 0;
        }
        else if(x1 == x2) {
            for(int t=y1; t<=y2; t++){
                maze[x1][t] = 0;
            }
        }
        else if(y1==y2) {
            for(int t=x1; t<=x2; t++){
                maze[t][y1] = 0;
            }
        }
        else if(x1 != x2 && y1 != y2) {
            int x = x1, y=y1;
            while(x<=x2 && y<=y2) {
                maze[x][y] = 0;
                x+=1;
                y+=1;
            }
            for(int t=y1; t<=y2; t++) maze[x1][t] = 0;
            for(int t=x1; t<=x2; t++) maze[t][y1] = 0;
            for(int t=x2; t>=x1; t--) maze[t][y2] = 0;
            for(int t=y2; t>=y1; t--) maze[x2][t] = 0;
        }
     }
     for(auto it: maze){
        for(auto iter: it){
            cout<<iter<<" ";
        }
        cout<<endl;
     }
    return mazeObstaclesUtil(maze, {0,0}, {N-1, M-1}, N, M);
}

int main() {
    int N = 5; 
    int M=5;
    vector<int> x1{0,3}, y1{2,0}, x2{2,4}, y2{4,1};
    int ans = solution(N, M, x1,y1, x2, y2);
    cout<<ans<<"kdj"<<endl;

}



int f(int ind, int target, vector<int> & vec, int n, vector<vector<int>>& dp){
    // base case 
    if(target == 0) return 0;
    if(ind == n) return 0;
    if(dp[ind][target] != -1) return dp[ind][target];
    int take = 1e9, nottake = 1e9;
    
    if(target >= vec[ind]) {
        take = 1 + f(ind, target - vec[ind], vec, n, dp);
    }
    else {
        return dp[ind][target] = vec[ind] - target;
    }
    
    nottake = f(ind+1, target, vec, n, dp);
    
    return dp[ind][target] = min(take, nottake);
}

int solution(vector<int> v, int p) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(p+1, -1));
    return f(0, p, v, n, dp);
}
