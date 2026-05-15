class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m= grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, vis, n,m,i,j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> & grid, vector<vector<bool>> &vis, int n, int m, int i, int j) {
        if(i >= n|| j >=m || i <0 || j <0 || vis[i][j] || grid[i][j]!='1') return;

        vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        vis[i][j] = 1;
        for(auto move: moves) {
            int newX = i +move.first;
            int newY = j + move.second;
            dfs(grid, vis, n,m,newX, newY);
        }
    }
};
