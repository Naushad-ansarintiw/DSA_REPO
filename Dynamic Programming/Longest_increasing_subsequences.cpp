int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp) {
    if(ind == n) return 0;

    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

    int len = 0 + f(ind+1, prev_ind, arr, n, dp);

    if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        len = max(len, 1+ f(ind+1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, arr, n);
}


// tabulatoin 
vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

for(int ind= n-1; ind>=0; ind--) {
    for(int prev_ind = ind-1, prev_ind>=-1; prev_ind--) {
        int len = 0 + dp[ind+1][prev_ind+1];

        if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
            len = max(len, 1+ dp[ind+1][ind+1]
        }
        dp[ind][prev_ind+1] = len;       
    }
}

return dp[0][-1+1];

// space optimization 
vector<int> next(n+1, 0), cur(n+1, 0);

for(int ind= n-1; ind>=0; ind--) {
    for(int prev_ind = ind-1, prev_ind>=-1; prev_ind--) {
        int len = 0 + next[prev_ind+1];

        if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
            len = max(len, 1+ next[ind+1]
        }
        cur[prev_ind+1] = len;       
    }
    next = cur;
}

return next[-1+1];


// different approach matching all characters from ind, 0 for every i

vector<int> dp(n, 1) , hash(n);

int maxi = 1;
int lastIndex = 0;

for(int i=0; i<n; i++){
    hash[i] = i;
    for(int prev = 0; prev<i; prev++) {
        if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]) {
            dp[i] = 1+dp[prev];
            hash[i] = prev;
        }
    }
    if(dp[i] > maxi) {
        maxi = dp[i];
        lastIndex = i;
    }
}

// maxi is the longest inc subsequence

// bachtrack to make longest inc subsequence

vector<int> temp;
temp.push_back(arr[lastIndex]);

while(hash[lastIndex] != lastIndex) {
    lastIndex = hast[lastIndex];
    temp.push_back(arr[lastIndex]);
}

reverse(temp.begin(), temp.end());

return temp;