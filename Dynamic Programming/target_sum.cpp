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

int targetSum(int n, int target, vector<int> &arr) {
    return countPartitions(n, target, arr); /// question similar to countPartitions
    
}