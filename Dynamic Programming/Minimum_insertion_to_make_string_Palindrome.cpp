// This is same as Longest Palindrome Subsequence question just reverse the string and pass it into the function and count the longest palindrome sequence length and ans is (total length - longest palindrome sequence length) 



// 2 method tabulation 

int lcs(string s, string t ) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++){
            if(s[i-1] == s[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }
 
   return  dp[n][m];

}


int longestPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}   


int minInsertion(string &str) {
    int lps = longestPalindrome(str);
    return str.size() - lps;
}