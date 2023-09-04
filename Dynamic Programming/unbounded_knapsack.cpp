int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
    // base case 
    if(ind == 0) {
        return (int)(W/wt[0]) * val[0];
    }
    
    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0 + f(ind-1, W, val, wt, dp);
    int take = 0;
    if(wt[ind] <= W) {
        take = val[ind] + f(ind, W-wt[ind], val, wt, dp);
    }

    return dp[ind][W] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, val , wt, dp);
}


// 2 method tabulation 

vector<vector<int>> dp(n, vector<int>(w+1, 0));

for(int W=0; W <= w; W++) dp[0][W] = (int)(W/wt[0]) * val[0];

for(int ind = 1; ind < n; ind++){
    for(int w=0; w <= w; w++) {
        int notTake = 0 + dp[ind-1][W];
        int take = 0;
        if(wt[ind] <= W) {
            take = val[ind] + dp[ind][W-wt[ind]];
        }

         dp[ind][W] = max(notTake, take);       
    }
}

return dp[n-1][W];

// 3 method space optimization 
vector<int> prev(w+1, 0), cur(w+1, 0);

for(int W=0; W <= w; W++) prev[W] = (int)(W/wt[0]) * val[0];

for(int ind = 1; ind < n; ind++){
    for(int w=0; w <= w; w++) {
        int notTake = 0 + prev[W];
        int take = 0;
        if(wt[ind] <= W) {
            take = val[ind] + curr[W-wt[ind]];
        }

        curr[W] = max(notTake, take);       
    }
    prev = curr
}

return prev[W];