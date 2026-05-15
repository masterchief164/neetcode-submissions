class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> path, vis;
        unordered_map<int, vector<int>> adj;
        vector<int> ans;

        for(auto pre: prerequisites)         {
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i = 0;i<numCourses; i++) {
            if (vis.find(i) == vis.end()) {
                if(!dfs(adj, path, vis, ans, i)){
                    return {};
                }
            }
        }

        // reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfs(unordered_map<int, vector<int>> &adj, unordered_set<int> &path, unordered_set<int> &vis,  vector<int>& ans, int i) {
        if(path.find(i) != path.end()) return 0;

        if(vis.find(i) != vis.end()) return 1;

        path.insert(i);
        for(auto x: adj[i]) {
            if(!dfs(adj, path, vis ,ans, x)) 
                return 0;
        }
        path.erase(i);
        vis.insert(i);
        ans.push_back(i);

        return 1;
    }
};
