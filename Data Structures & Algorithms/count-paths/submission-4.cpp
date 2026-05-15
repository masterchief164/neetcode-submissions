class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));

        dp[n-1][m-1] = 1;

        for(int i = n-1;i>=0;i--) {
            for(int j = m-1;j>=0;j--) {
                dp[i][j] +=(dp[i+1][j]+dp[i][j+1]);
            }
        }
        return dp[0][0];
        // return dfs(0,0,n,m, dp);
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>>& dp) {
        if(i == (n-1) && j == (m-1)) return 1;
        int ans = 0;
        if(i >=n || j >=m) return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        vector<pair<int, int>> moves = {{0,1}, {1,0}};
        for(auto x: moves) {
            int nx = x.first + i, ny = x.second + j;
            ans+=dfs(nx, ny, n,m, dp);
        }

        return dp[i][j] = ans;


    }
};
