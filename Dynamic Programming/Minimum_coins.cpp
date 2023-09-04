int f(int ind, int T, vector<int> & nums, vector<vector<int>> & dp) {
    if(ind == 0) {
        if(T % nums[0] == 0) return T / nums[0];
        return 1e9;
    }
    
    if(dp[ind][T] != -1) return dp[ind][T];
        int notTake = 0 + f(ind -1, T, nums, dp);
        int take = INT_MAX;
        if(nums[ind] <= T) take = 1 + f(ind, T-nums[ind], nums,dp);

        return dp[ind][T]= min(notTake,take);

}

int minimumElement(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    int ans = f(n-1, target, nums);

    if(ans >= 1e9) return ans;
    else return -1;
}


// 2 method tabulatoin 

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int T=0; T<=target; T++) {
        if(T%nums[0] == 0) dp[0][T] = T/nums[0];
        else dp[0][T] = 1e9;
    }

    for(int ind=1; ind<n; ind++){
        for(int t = 0; t<=target; t++) {
                int notTake = 0 + dp[ind-1][t];
                int take = INT_MAX;
                if(nums[ind] <= T) take = 1 + dp[ind][t-nums[ind]];

                dp[ind][T]= min(notTake,take);           
        }
    }

    int ans = dp[n-1][target];

    if(ans >= 1e9) return ans;
    else return -1;

// 3 method space optimize

    int n = nums.size();
    vector<int> prev(target+1, 0), cur(target+1, 0);

    for(int T=0; T<=target; T++) {
        if(T%nums[0] == 0) prev[T] = T/nums[0];
        else prev[T] = 1e9;
    }

    for(int ind=1; ind<n; ind++){
        for(int t = 0; t<=target; t++) {
                int notTake = 0 + prev[t];
                int take = INT_MAX;
                if(nums[ind] <= T) take = 1 + cur[t-nums[ind]];

                curr[T]= min(notTake,take);           
        }
        prev = cur;
    }

    int ans = prev[target];

    if(ans >= 1e9) return ans;
    else return -1;
