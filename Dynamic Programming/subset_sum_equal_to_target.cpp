// 1 method memoization

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr);
    bool take = false;
    if(a[ind] <= target) take = f(ind-1, target-arr[ind], arr);

    return dp[ind][target] = take or notTake;
}

bool subsetSumTok(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<bool>(k+1, -1));
    return f(n-1, k, arr, dp);
}

// 2 method tabulation

vector<vector<bool>> dp(n, vector<int>(k+1, 0));

for(int i=0; i<n; i++) dp[i][0] = true;
dp[0][arr[0]] = true;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = dp[ind-1][target];
        bool take = false;
        if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

        dp[ind][target] = take or notTake;
    }
}

return dp[n-1][k];

// 3 method space optimization 

vector<bool> prev(k+1, 0), curr(k+1, 0);
prev[0] = curr[0] = true;
prev[arr[0]] = true;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = prev[target];
        bool take = false;
        if(a[ind] <= target) take = prev[target-arr[ind]];

        curr[target] = take or notTake;
    }
    prev = curr;
}

return prev[k];