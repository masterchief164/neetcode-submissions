class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (n, vector<int> (m, -1));
        return helper(0,0,n,m, dp);
    }
    int helper(int i, int j, int &n, int &m, vector<vector<int>> &dp) {
        if(i == n-1 && j == m-1) return 1;

        if(i>=n || j >=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = helper(i+1, j, n,m, dp) + helper(i, j+1, n, m, dp);
    }
};