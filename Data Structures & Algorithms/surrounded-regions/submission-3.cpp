class Solution {
public:
vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0, n,m);
            }
            if(board[i][m-1] == 'O') {
                dfs(board, i, m-1, n,m);
            }
        }
        for(int j = 0;j<m;j++) {
            if(board[n-1][j] == 'O') {
                dfs(board, n-1, j, n,m);
            }
            if(board[0][j] == 'O') {
                dfs(board, 0, j, n,m);
            }
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'V'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j, int n, int m) {
        if(i >=n || j >=m || i <0 || j <0 || board[i][j] !='O')
            return;

        board[i][j] = 'V';
        for(auto x: moves) {
            dfs(board, i+x.first, j+x.second, n,m);
        }
    }
};
