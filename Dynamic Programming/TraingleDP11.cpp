// 1 method memorization 

int f(int i, int j, vector<vector<int>> & traingle, int n,  vector<vector<int>>& dp){
    // base case 
    if(i == n-1) return traingle[n-1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int d = traingle[i][j] + f(i+1, j, traingle, n);
    int dg = traingle[i][j] + f(i+1, j+1,traingle, n);

    return dp[i][j] = min(d,dg);

}

int minimumPathSum(vector<vector<int>> & traingle, int n){
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return f(0,0,traingle, n, dp);
}


// 2 method tabulation
vector<vector<int>> dp(n, vector<int>(n,0));

for(int j=0; j<n; j++) dp[n-1][j] = traingle[n-1][j]; 

for(int i=n-2; i>=0; i--){
    for(int j = i; j>=0; j--){
        int d = traingle[i][j] + dp[i+1][j];
        int dg = traingle[i][j] + dp[i+1][j+1];

        dp[i][j] = min(d, dp);
    }
}

return dp[0][0];


// 3 method optimization
vector<int> front(n,0), curr(n,0);

for(int j=0; j<n; j++) front[j] = traingle[n-1][j]; 

for(int i=n-2; i>=0; i--){
    for(int j = i; j>=0; j--){
        int d = traingle[i][j] + front[j];
        int dg = traingle[i][j] + front[j+1];

        curr[j] = min(d, dp);
    }
    front = curr;
}

return front[0];
