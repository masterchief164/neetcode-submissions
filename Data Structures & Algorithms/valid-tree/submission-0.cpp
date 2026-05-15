class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> vis;
        vector<vector<int>> adj(n, vector<int> ());

        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        if(!dfs(0, -1, vis, adj)) return 0;

        return vis.size() == n;
    }

    bool dfs(int c, int prev, unordered_set<int> &vis, vector<vector<int>> &adj){
        if(vis.count(c)) return 0;

        vis.insert(c);
        for(auto x: adj[c]){
            if(x == prev) continue;

            if(!dfs(x, c, vis, adj)) return 0;
        }
        return 1;
    }
};
