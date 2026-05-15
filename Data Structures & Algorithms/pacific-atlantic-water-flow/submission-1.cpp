class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pac (n, vector<int>(m,0));
        vector<vector<int>> alt (n, vector<int>(m,0));

        for(int i = 0;i<m;i++){
            dfs(heights, pac, n,m, 0, i);
            dfs(heights, alt, n,m, n-1, i);
        }

         for(int i = 0;i<n;i++){
            dfs(heights, pac, n,m, i, 0);
            dfs(heights, alt, n,m, i, m-1);
        }

        vector<vector<int>> res;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(alt[i][j] && pac[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int &n, int &m, int i , int j){
        ocean[i][j] = 1;
        vector<pair<int, int>> moves = {{-1,0}, {0, -1}, {1,0}, {0,1}};
        for(auto [x, y]: moves) {
            int nx = i+ x, ny = j + y;
            if(nx >= 0 && ny >=0 && nx < n && ny < m && !ocean[nx][ny] && heights[i][j] <= heights[nx][ny]){
                dfs(heights, ocean, n, m, nx, ny);
            }
        }
    }
};
