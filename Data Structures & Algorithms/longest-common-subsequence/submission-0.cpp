class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m ,-1));
        return helper(0, 0, n, m, text1, text2, dp);
    }

    int helper(int i, int j, int &n, int &m, string &a, string &b, vector<vector<int>> &dp) {
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]) ans = 1+ helper(i+1, j+1, n, m, a, b, dp);

        ans = max(ans, helper(i, j+1, n, m, a, b, dp));
        ans = max(ans, helper(i+1, j, n, m, a, b, dp));
        return dp[i][j] = ans;
    }
};
