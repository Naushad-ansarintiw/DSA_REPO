bool f(int i, int j, string &a, string &b, vector<vector<bool>> &dp) {
    // base cases
    if(i==0 && j==0) return true;
    if(i==0 && j>0) return false;
    if(j==0 && i>0) {
        for(int t=1; t<=i; t++) {
            if(a[t-1] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != false) return dp[i][j];

    if(a[i-1] == b[j-1] || a[i-1] == '?') return dp[i][j] = f(i-1, j-1, a, b, dp);
    if(a[i-1] == '*') return dp[i][j] = f(i-1, j, a, b, dp) | f(i, j-1, a, b, dp);
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text) {
    int n = pattter.size();
    int m = text.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    return f(n, m, pattern, text, dp);
}


// tabulation 

    int n = pattter.size();
    int m = text.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // base cases
// ----------------------
    dp[0][0] = true;
    for(int j=1; j<=m; j++) {
        dp[0][j] = false;
    }
    for(int i=1; i<=n; i++) {
        int fl = true;
        for(int t=1; t<=i; t++) {
            if(a[t-1] != '*') {
               fl = false;
               break;
            }
        }
        dp[i][0] = fl;
    }
// --------------
for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
        if(a[i-1] == b[j-1] || a[i-1] == '?') dp[i][j] = dp[i-1][j-1];
        else if(a[i-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
        else dp[i][j] = false;        
    }
}

return dp[n][m];


// 3 space optimization 

    int n = pattter.size();
    int m = text.size();
    vector<bool> prev(m+1, false), cur(m+1, false);

    // base cases
// ----------------------
    prev[0] = true;
    for(int j=1; j<=m; j++) {
        prev[j] = false;
    }
// --------------
for(int i=1; i<=n; i++) {
        int fl = true;
        for(int t=1; t<=i; t++) {
            if(a[t-1] != '*') {
               fl = false;
               break;
            }
        }
        cur[0] = fl;

    for(int j=1; j<=m; j++) {
        if(a[i-1] == b[j-1] || a[i-1] == '?') cur[j] = prev[j-1];
        else if(a[i-1] == '*') cur[j] = prev[j] | cur[j-1];
        else cur[j] = false;        
    }
    prev = cur;
}

return prev[m];
