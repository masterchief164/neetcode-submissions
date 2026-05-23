class Solution {
    public void islandsAndTreasure(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        Queue<int[]> q = new LinkedList<>();

        for(int i =0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 0)
                    q.offer(new int[]{i,j});
            }
        }

        int[][] dirs = { { -1, 0 }, { 0, -1 },
                         { 1, 0 }, { 0, 1 } };


        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int i = curr[0], j = curr[1];

            for(int [] dir: dirs) {
                int nx = i + dir[0];
                int ny = j + dir[1];

                if(nx<0 ||ny<0||nx>=n ||ny>=m|| grid[nx][ny] != Integer.MAX_VALUE ){
                    continue;
                }
                q.offer(new int[] {nx, ny});

                grid[nx][ny] = 1 + grid[i][j];
            }
        }

        if(q.size() == 0) return;

    }
}
