class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int [][]dp = new int[n][m];
        int ans= 0;

        for(int[] d: dp) {
            Arrays.fill(d, -1);
        }

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                ans = Math.max(dfs(dp, matrix, i,j,Integer.MIN_VALUE), ans);
            }
        }
        return ans;
    }

    private int dfs(int[][] dp, int[][] matrix, int i, int j, int prev) {
        int n = matrix.length, m = matrix[0].length;
        if(i<0 || j<0 || i>=n||j>=m||matrix[i][j] <= prev) {
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        int[][] dir = {{0,1}, {1,0},{-1,0},{0,-1}};

        for(int[] d: dir) {
            int nx = i + d[0];
            int ny = j + d[1];

            ans = Math.max(ans,1+ dfs(dp, matrix, nx, ny, matrix[i][j]));
        }

        dp[i][j] = ans;
        return ans;
    }
}
