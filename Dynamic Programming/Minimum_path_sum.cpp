// 1 method memorization

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
   if(i == 0 && j == 0) return grid[i][j];
   if(i < 0 || j < 0) return 1e9;

   if(dp[i][j] != -1) return dp[i][j];

   int up = grid[i][j] + f(i-1, j, grid, dp);
   int left = grid[i][j] + f(i, j-1, grid, dp); 
   return dp[i][j] = min(up, left);
}

int minSumPath (vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1, m-1, grid);
}


// 2 method tabulation 

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j], left = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            } 
        }
    }
    
    return dp[n-1][m-1];


// 3 method space optimization
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,0);

    for(int i=0; i<n; i++){
         vector<int> curr(m,0);
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j], left = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                if(j>0) left += curr[j-1];
                else left += 1e9;

                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    
    return prev[m-1];