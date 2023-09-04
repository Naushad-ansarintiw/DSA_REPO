// 1 method memoization

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> dp){
    if(ind == 0) {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || target == arr[0]) return 1;
        return 0;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr);
    bool take = false;
    if(a[ind] <= target) take = f(ind-1, target-arr[ind], arr);

    return dp[ind][target] = take+notTake;
}

int countPartitions(int n, int d, vector<int> &arr){
    int totalSum = 0;
    for(auto it: arr) totalSum += it;
    if(totalSum - d <0 || (totalSum - d)%2) return false;

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(((totalSum-d)/2) + 1, -1));
    return f(n-1,(totalSum-d)/2, arr,dp); 
}

// 2 method tabulation

vector<vector<bool>> dp(n, vector<int>(k+1, 0));

if(arr[0] == 0) dp[0][0] = 2;
else dp[0][0] = 1;

if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = dp[ind-1][target];
        bool take = false;
        if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

        dp[ind][target] = take+notTake;
    }
}

return dp[n-1][k];

// 3 method space optimization 

vector<bool> prev(k+1, 0), curr(k+1, 0);
if(arr[0] == 0) prev[0] = 2;
else prev[0] = 1;

if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

for(int ind = 1; ind < n; ind++){
    for(int target = 1; target <=k; target++) {
        bool notTake = prev[target];
        bool take = false;
        if(a[ind] <= target) take = prev[target-arr[ind]];

        curr[target] = take + notTake;
    }
    prev = curr;
}

return prev[k];
