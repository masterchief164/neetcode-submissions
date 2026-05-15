class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i = 0;i<=n;i++) {
            dp[i][0]= 0;
        }

        for(int i = 0;i<=m;i++) {
            dp[0][i]= 0;
        }

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<m+1;j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

        // return dfs(text1, text2, text1.size(), text2.size(), dp);
    }

    int dfs(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i-1] == b[j-1]) {
            return dp[i][j] = 1+dfs(a, b, i-1,j-1, dp);
        }
        return dp[i][j] = max({dfs(a,b,i,j-1,dp), dfs(a,b,i-1, j,dp)});
    }
};
