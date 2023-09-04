int lcs(string &str1, string &str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<n; i++) dp[i][0] = 0;
    int maxi = INT_MIN;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i-1] == str2[j-1]) {
                 dp[i][j] = 1 + dp[i-1][j-1];
                 maxi = max(maxi, dp[i][j]);
            }
            else dp[i][j] = 0;       
        }
    }

    return maxi;
}


// 2 method space optimizarion 

int lcs(string &str1, string &str2) {
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int j=0; j<=m; j++) prev[j] = 0;
    for(int i=0; i<n; i++) curr[0] = 0;
    int maxi = INT_MIN;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i-1] == str2[j-1]) {
                 dp[i][j] = 1 + prev[j-1];
                 maxi = max(maxi, curr[j]);
            }
            else curr[j] = 0;       
        }
        prev = curr;
    }

    return maxi;
}