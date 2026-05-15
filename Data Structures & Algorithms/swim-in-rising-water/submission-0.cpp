class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        vector<pair<int, int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        set<pair<int, int>> vis;
        int n = grid.size();
        int m = grid[0].size();

        minHeap.push({grid[0][0], 0,0});

        while(minHeap.size()){
            auto [maxi, r, c] = minHeap.top();
            minHeap.pop();

            if(vis.count({r, c})){
                continue;
            }

            vis.insert({r,c});

            if(r == n-1 && c == m-1) return maxi;

            for(auto [x, y]: moves){
                int nr = r +x, nc= c + y;
                if(nr<n && nr >=0 &&nc >= 0 && nc < m && !vis.count({nr, nc})){
                    minHeap.push({max(maxi, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};