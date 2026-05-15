class Solution {
public:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i= 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                ans = max(ans, dfs(i,j,n,m,matrix, INT_MIN, dp));
            }
        }
        return ans;
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix, int prev, vector<vector<int>> &dp) {
        if(i>=n || j >=m || j<0||i<0 || matrix[i][j] <= prev) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int res = 1;
        for(auto x: dir) {
            res = max(res,1 + dfs(i+x.first, j+x.second, n, m, matrix, matrix[i][j], dp));
        }
        return dp[i][j] = res;
    }
};
