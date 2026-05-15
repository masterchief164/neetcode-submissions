class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        unordered_set<int> vis;
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }

        for(int c = 0; c<numCourses; c++){
            if(!dfs(c, adj, vis)){
                return 0;
            }
        }
        return 1;
    }

    bool dfs(int c, vector<vector<int>> &adj, unordered_set<int> &vis){
        if(vis.find(c) != vis.end()) return 0;

        vis.insert(c);
        for(auto x: adj[c]){
            if(!dfs(x, adj, vis)) return 0;
        }
        vis.erase(c);
        adj[c] = {};
        return 1;
    }
};
