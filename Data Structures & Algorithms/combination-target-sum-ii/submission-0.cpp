class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, ans, 0, target, n, 0, path);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>> &ans, int i, int t, int n, int curr, vector<int> path) {
        if(curr == t) {
            ans.push_back(path);
            return;
        }

        if(curr > t || i >= n) return;

        path.push_back(candidates[i]);
        dfs(candidates, ans, i + 1, t, n, curr + candidates[i], path);
        path.pop_back();

        while(i+1 <n && candidates[i] == candidates[i+1])
            i++;

        dfs(candidates, ans, i+1, t, n, curr, path);
    }
};
