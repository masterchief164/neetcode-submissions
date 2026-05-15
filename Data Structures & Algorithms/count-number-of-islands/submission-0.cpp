class Solution {
public:
    vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i , j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int &n, int &m){
        if(i>=n || j >=m || i <0 || j < 0 || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        for(auto move: moves){
            dfs(grid, i+move.first, j +move.second, n,m);
        }
    }
};
