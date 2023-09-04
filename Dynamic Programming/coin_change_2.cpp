long f(int ind, int T, int *a) {
    if(ind == 0) return (T%a[0] == 0);

    if(dp[ind][T] != -1) return dp[ind][T];
    long notTake = f(ind-1, T, a);
    long take = 0;
    if(a[ind] <= T) take = f(ind, T-a[ind], a);

    return dp[ind][T] = take + notTake;

}

long countWaysToMakeChange(int *denomination, int n, int value){
    vector<vector<int>> dp(n, vector<int>(value+1, -1));
    return f(n-1, value, denomination);
}

// 2 method tabulation

    vector<vector<int>> dp(n, vector<int>(value+1, 0));

    for(int T=0; T<=value; T++) dp[0][T] = (T%a[0] == 0);

    for(int ind = 1; ind<n; ind++){
        for(int T=0; T<=value; T++){
            long notTake = dp[ind-1][T];
            long take = 0;
            if(a[ind] <= T) take = dp[ind][T-a[ind]];

            dp[ind][T] = take + notTake;       
        }
    }

    return dp[ind-1][value];

// 3 method space obtimize

    vector<int> prev(value+1, 0), cur(value+1, 0);

    for(int T=0; T<=value; T++) prev[T] = (T%a[0] == 0);

    for(int ind = 1; ind<n; ind++){
        for(int T=0; T<=value; T++){
            long notTake = prev[T];
            long take = 0;
            if(a[ind] <= T) take = cur[T-a[ind]];

            cur[T] = take + notTake;       
        }
        prev = cur;
    }

    return prev[value];