class Solution {
    public boolean exist(char[][] board, String word) {
        int n = board.length, m = board[0].length;
        boolean[][] vis = new boolean[n][m];

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++) {
                if(dfs(i,j,0,word, board, n,m,vis))
                    return true;
            }
        }
        return false;
    }

    private boolean dfs(int i, int j, int k, String word, char[][] board, int n, int m , boolean[][]vis){
        if(k == word.length()) return true;
        if(i >=n || j >= m || i<0||j<0 || k >= word.length() || word.charAt(k) != board[i][j] || vis[i][j]) return false;

        boolean ans = false;
        int [][] directions = {{1,0}, {0,1}, {-1,0},{0,-1}};
        vis[i][j]= true;

        for(int []direction: directions) {
            int nx = i + direction[0];
            int ny = j + direction[1];
            ans |=dfs(nx, ny, k+1, word, board, n,m, vis);
        }

        vis[i][j] = false;

        return ans;
    }
}
