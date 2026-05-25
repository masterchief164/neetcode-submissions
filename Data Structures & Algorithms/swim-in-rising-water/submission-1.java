class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;

        boolean[][] vis = new boolean[n][n];
        int l = grid[0][0], r = grid[0][0];
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                l = Math.min(grid[i][j], l);
                r = Math.max(r, grid[i][j]);
            }
        }

        while(l<r) {
            int m = (l+r)>>1;
            if(dfs(0,0,n,grid,vis,m)) {
                r = m;
            } else {
                l = m+1;
            }

            for(int i = 0;i<n;i++) {
                Arrays.fill(vis[i], false);
            }
        }
        return r;
    }

    public boolean dfs(int i, int j, int n, int [][]grid,boolean[][] vis, int k) {
        if(i < 0 || j < 0 || i>=n || j>=n || vis[i][j] || grid[i][j] > k) {
            return false;
        }

        if(i ==n-1 && j == n-1) {
            return true;
        }

        vis[i][j] = true;

        return  dfs(i+1,j,n,grid, vis, k) ||
                dfs(i,j+1,n,grid, vis, k) ||
                dfs(i,j-1,n,grid, vis, k) ||
                dfs(i-1,j,n,grid, vis, k);

    }
}
