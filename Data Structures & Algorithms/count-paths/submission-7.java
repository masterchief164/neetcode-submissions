class Solution {
    public int uniquePaths(int m, int n) {
        int [][]dp = new int[m+1][n+1];

        for(int []it: dp) {
            Arrays.fill(it, -1);
        }

        return dfs(m,n,0,0, dp);
    }

    public int dfs(int m, int n, int i, int j, int [][]dp) {
        if(i == m-1 && j ==n-1)
            return dp[i][j] = 1;
        if(dp[i][j] !=-1) return dp[i][j];
        if(i >= m || j >=n) return 0;

        return dp[i][j] = dfs(m,n,i+1,j, dp) + dfs(m,n,i,j+1, dp);
    }
}
