class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());

        unordered_map<string, deque<string>> adj;

        for(auto x: tickets) {
            adj[x[0]].push_back(x[1]);
        }

        vector<string> ans;

        dfs("JFK", ans, adj);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string s, vector<string> &ans, unordered_map<string, deque<string>> &adj) {
        while(adj[s].size()) {
            string dest = adj[s].back();
            adj[s].pop_back();
            dfs(dest, ans, adj);
        }
        ans.push_back(s);
    }
};
