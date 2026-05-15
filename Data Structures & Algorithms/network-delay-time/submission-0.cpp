class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, u] = pq.top();
            pq.pop();

            if(time > dist[u]) {
                continue;
            }
            
            for(const auto& edge : adj[u]){
                int v = edge.first;
                int travel_time = edge.second;

                if(dist[u] + travel_time < dist[v]){
                    dist[v] = dist[u] + travel_time;
                    pq.push({dist[v], v}); 
                }
            }
        }

        int max_delay = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            max_delay = max(max_delay, dist[i]);
        }
        
        return max_delay;
    }
};