class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));


        return dfs(text1, text2, text1.size(), text2.size(), dp);
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
