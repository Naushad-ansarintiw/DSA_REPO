int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notpick = 0 + f(ind-1, nums, dp);

    return dp[ind] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n-1, nums);
}

// tabulated form 

dp[0] = a[0];
int neg = 0
for(int i=1; i<n; i++){
    take = a[ind] + (i>1) ? dp[i-2] : neg;
    nottake = 0 + dp[i-1];

    dp[i] = max(take, nottake);
}

return dp[n-1];


// space optimize 

int n = nums.size();
int prev = nums[0];
int prev2 = 0;

for(int i=1; i<n; i++){
    int take = nums[i];
    if(i>1) take += prev2;

    int notTake = 0 + prev;

    int curi = max(take, notTake);
    prev2 = prev;
    prev = curi;
}

return prev;
