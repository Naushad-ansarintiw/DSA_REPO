int mod = (int)(1e9 + 7);
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if( i>=0 && j>=0 && mat[i][j] == -1) return 0;
    if( i==0 && j==0 ) return 1;
    if( i<0 || j<0 ) return 0;

    if(dp[i][j] == -1) return dp[i][j];

    int up = f(i-1, j, mat, dp);
    int left = f(i, j-1, mat, dp);
    return dp[i][j] = (up+left)%mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> & mat){
    // 1 memorization
    vector<vector<int>> dp(m, vector<int>(n,0));
    return f(n-1, m-1, mat, dp);
}


// =======2 method tabulation

int dp[n][m];
for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        if(mat[i][j] == -1) dp[i][j] = 0;
        else if(i == 0 && j == 0) dp[i][j] = 1;
        else {
            int up = 0, left = 0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
}

return dp[n-1][m-1];



// - ---- 3 method space obtimization 

vector<int> prev(m,0);
for(int i=0; i<n; i++) {
    vector<int> curr(m, 0);
    for(int j=0; j<m; j++) {
        if(mat[i][j] == -1) curr[j] = 0;
        else if(i == 0 && j == 0) curr[j] = 1;
        else {
            int up = 0, left = 0;
            if(i>0) up = prev[j];
            if(j>0) left = curr[j-1];
            curr[j] = up + left;
        }
    }
    prev = curr;
}

return prev[m-1];