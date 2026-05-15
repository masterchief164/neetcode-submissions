class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,0});
        int ans = 0;
        vector<bool> vis(n, 0);

        while(pq.size()){
            auto f = pq.top();
            pq.pop();
            if(vis[f.second]) continue;
            ans+=f.first;
            vis[f.second] =1;

            for(auto x: adj[f.second]) {
                if(vis[x.second])
                    continue;
                pq.push({x.first, x.second});
            }
            
        }
        return ans;
    }
};
