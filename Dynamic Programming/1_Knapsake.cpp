// Most Important

// 1 method memoization 

int f(int ind, int W, vector<int> &wt, vector<int> & val, vector<vector<int>> & dp){
    if(ind == 0){
        if(wt[0] <= W ) return val[0];
        else return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    int nottake = f(ind-1, W, wt, val, dp);
    int take = 0;
    if(wt[ind] <= W) take += val[ind] + f(ind-1, W-wt[ind], wt, val, dp);

    return dp[ind][W]=max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}

// 2 method tabulation

vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

for(int W=weight[0]; W <=maxWeight; W++) dp[0][W] = value[0];

for(int ind = 1; ind<n; ind++){
    for(int W = 0; W <= maxWeight; W++){
        int nottake = dp[ind-1][W];
        int take = 0;
        if(wt[ind] <= W) take += val[ind] + dp[ind-1][W-weight[ind]];

         dp[ind][W]=max(take,nottake);      
    }
}

return dp[N-1][maxWeight];

// 3 method space-optimize

vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

for(int W=weight[0]; W <=maxWeight; W++) prev[W] = value[0];

for(int ind = 1; ind<n; ind++){
    for(int W = 0; W <= maxWeight; W++){
        int nottake = prev[W];
        int take = 0;
        if(wt[ind] <= W) take += val[ind] + prev[W-weight[ind]];

        curr[W]=max(take,nottake);      
    }
    prev = curr;
}

return prev[maxWeight];