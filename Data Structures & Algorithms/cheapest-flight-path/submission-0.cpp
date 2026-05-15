class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n, INT_MAX);
        costs[src] =0;

        vector<vector<pair<int, int>>> adj(n);

        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<vector<int>> pq;
        
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto curr = pq.front();
            pq.pop();

            int cCost = curr[0];
            int cNode = curr[1];
            int cEdges = curr[2];

            if (cEdges > k) {
                continue;
            }

            for (auto& next : adj[cNode]) {
                int nNode = next.first;
                int nPrice = next.second;

                int newCost = cCost + nPrice;
                int newEdges = cEdges + 1;

                if (newCost < costs[nNode]) {
                    costs[nNode] = newCost;
                    pq.push({newCost, nNode, newEdges});
                }
            }
        }

        return (costs[dst] == INT_MAX) ? -1 : costs[dst];
    }
};