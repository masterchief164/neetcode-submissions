class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return dfs(text1, text2, 0,0, dp);
    }

    int dfs(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if(i == a.size() || j == b.size()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]) {
            return dp[i][j] = 1+dfs(a, b, i+1,j+1, dp);
        }
        return dp[i][j] = max({dfs(a,b,i,j+1,dp), dfs(a,b,i+1, j,dp)});
    }
};
