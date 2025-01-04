class Solution {
public:
    signed lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // int dp[n+1][m+1];
        // memset(dp, 0, sizeof dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {

                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }

                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int helper(string s) {
        string newStr = s;
        reverse(newStr.begin(), newStr.end());

        return lcs(s, newStr);
    }
    int maxProduct(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<=(1<<n); i++) {
            string x = "", y = "";

            for(int j=0; j<n; j++) {
                if((1<<j) & i) 
                    x += s[j];

                else {
                    y += s[j];
                }
            }

            ans = max(ans, helper(x)* helper(y));
        }
        return ans;
    }
};
