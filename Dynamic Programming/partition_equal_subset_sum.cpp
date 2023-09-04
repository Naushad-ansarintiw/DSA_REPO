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

bool canPartition(vector<int> &arr, int n){
    int totalSum = 0;
    for(auto it: arr) {
        totalSum += it;
    }

    // if sum is odd then it's not possible to partition
    if(totalSum & 1 ) return false;
    
    int target = totalSum/2;
    vector<vector<int>> dp(n, vector<int>(target, -1));
    return f(n-1, target, arr, dp);

}

// 2 method tabulation 
int totalSum = 0;
for(auto it: arr) {
    totalSum += it;
}
// if sum is odd then it's not possible to partition
if(totalSum & 1 ) return false;

int target = totalSum/2;
vector<vector<bool>> dp(n, vector<int>(target+1, 0));

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

return dp[n-1][target];


// 3 method space optimization 
int totalSum = 0;
for(auto it: arr) {
    totalSum += it;
}
// if sum is odd then it's not possible to partition
if(totalSum & 1 ) return false;

int target = totalSum/2;

vector<bool> prev(target+1, 0), curr(target+1, 0);
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

return prev[target];