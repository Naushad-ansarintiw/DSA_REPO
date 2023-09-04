// 1 method memoization

int f(int ind, int target, vector<int> &arr, vector<vector<int>> dp){
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;
    if(a[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take + notTake;
}


int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return f(n-1, tar, num, dp);
}


// 2 method tabulation
int n = num.size();
vector<vector<bool>> dp(n, vector<int>(tar+1, 0));

for(int i=0; i<n; i++) dp[i][0] = 1;
if(a[0] < tar+1) dp[0][arr[0]] = 1;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = dp[ind-1][target];
        bool take = 0;
        if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

        dp[ind][target] = take + notTake;
    }
}

return dp[n-1][k];

// 3 method space optimization 

vector<bool> prev(k+1, 0), curr(k+1, 0);
prev[0] = curr[0] = 1;
if(a[0] < tar+1) prev[arr[0]] = 1;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = prev[target];
        bool take = 0;
        if(a[ind] <= target) take = prev[target-arr[ind]];

        curr[target] = take + notTake;
    }
    prev = curr;
}

return prev[k];