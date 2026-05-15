class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vis(n, 0);

        int ans = 0;

        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for(int i = 0;i<n;i++) {
            if(!vis[i]){
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }

    void dfs(int c,  vector<bool> &vis, vector<vector<int>> &adj){
        if(vis[c]) return;
        vis[c] = 1;
        for(auto x: adj[c]){
            dfs(x, vis, adj);
        }
    }
};
 