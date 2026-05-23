class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int r = grid.length, c= grid[0].length;
        boolean[][] vis= new boolean[r][c];

        int ans = 0;
        for(int i=0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                if(grid[i][j] == 1){
                    ans = Math.max(dfs(r,c,i,j, grid, vis), ans);
                }
            }
        }
        return ans;
    }

    private int dfs(int r, int c, int i, int j, int[][] grid, boolean[][]vis) {
        if(i >=r || j>=c||i<0||j<0||grid[i][j]==0||vis[i][j]) return 0;

        int[][] direction = {{1,0},{0,1},{-1,0},{0,-1}};
        int ans = 1;
        vis[i][j] = true;

        for(int[]di: direction) {
            int nx = i+di[0];
            int ny = j+di[1];

            ans += dfs(r,c,nx,ny, grid, vis);
        }
        return ans;
    }
}
