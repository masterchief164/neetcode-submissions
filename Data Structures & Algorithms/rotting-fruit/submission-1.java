class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;

        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        int time = 0;

        for(int i =0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 2)
                    q.offer(new int[]{i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int[][] dirs = { { -1, 0 }, { 0, -1 },
                         { 1, 0 }, { 0, 1 } };


        while(!q.isEmpty() && fresh > 0) {
            int s = q.size();
            for(int k = 0; k<s;k++){
                int[] curr = q.poll();
                int i = curr[0], j = curr[1];

                for(int [] dir: dirs) {
                    int nx = i + dir[0];
                    int ny = j + dir[1];

                    if(nx<0 ||ny<0||nx>=n ||ny>=m|| grid[nx][ny] != 1){
                        continue;
                    }
                    grid[nx][ny] = 2;
                    fresh--;
                    q.offer(new int[] {nx, ny});

                    grid[nx][ny] = 1 + grid[i][j];
                }
            }
            time++;
        }
        if(fresh > 0) return -1;

        return time;
        
    }
}
