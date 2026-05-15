class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis = vector(n, vector<int>(m, 0));

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(works(vis, i,j,0,n,m,board, word)) return 1;
            }
        }
        return 0;
    }

    bool works(vector<vector<int>> &vis, int r, int c, int i, int &n, int &m, vector<vector<char>> &board, string &word){
        if(i == word.size()){
            return 1;
        }

        if(r<0 || c <0 || r>=n || c>=m || board[r][c] != word[i] || vis[r][c]) return 0;

        vis[r][c] = 1;

        bool ans = works(vis, r +1, c, i+1, n,m,board, word) ||
                   works(vis, r -1, c, i+1, n,m,board, word) ||
                   works(vis, r, c +1, i+1, n,m,board, word) ||
                   works(vis, r, c -1, i+1, n,m,board, word);
        vis[r][c] = 0;
        return ans;
    }
};
