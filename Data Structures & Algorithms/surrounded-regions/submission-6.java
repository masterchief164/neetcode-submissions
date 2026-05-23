class Solution {
    public void solve(char[][] board) {
        int n = board.length, m = board[0].length;

        capture(board);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }

    private void capture(char[][] board) {
        int n = board.length, m = board[0].length;
        Queue<int[]> q = new LinkedList<>();
        int[][] dirs = new int[][] {
            {1,0}, {0,1},
            {-1,0}, {0,-1}
        };

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if((i ==0 || j ==0 || j == m-1 || i == n-1) && board[i][j] == 'O'){
                    board[i][j] = 'T';
                    q.offer(new int[]{i,j});
                }
            }
        }

        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int i = curr[0], j = curr[1];

            for(int[] dir: dirs) {
                int nx = i + dir[0], ny = j + dir[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = 'T';
                    q.offer(new int[] {nx, ny});
                }
            }
        }
    }
}
