class Solution {
public:
    vector<pair<int, int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), tmp = 0, ans = 0;
        for(int i = 0; i<n;i++) {
            for(int j =0;j<m;j++) {
                if(grid[i][j] == 1) {
                    tmp = 0;
                    dfs(i,j,grid, tmp, n,m);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, int &ans, int n, int m) {
        if(x<0 || y<0|| x>=n || y>=m || grid[x][y] != 1) {
            return;
        }
        ans++;
        grid[x][y] = -1;
        // int is = 1;
        for(auto move: moves) {
            dfs(x+move.first, y+move.second, grid, ans, n,m);
        }
        // return is;
    }
};
