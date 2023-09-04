int f(int ind, vector<int> &heights , vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int minSteps = INT_MAX;
    for(int i=1; i<=k; i++){
        if(ind-i>=0) {
            int jump = f(ind-i, heights, dp) + abs(heights[ind] - heights[ind-i]);
        }
        else break;

        minSteps = min(minSteps, jump);
    }
    return dp[ind] = minSteps;
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return f(n-1, heights,dp);
}