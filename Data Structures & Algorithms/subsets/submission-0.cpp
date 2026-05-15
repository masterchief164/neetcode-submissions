class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0, n= nums.size();
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(ans, nums, curr, 0, n);
        return ans;

    }
    void dfs(vector<vector<int>>& ans, vector<int> &nums, vector<int> curr, int i, int n) {
        if(i == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(ans, nums, curr, i+1, n);
        curr.pop_back();
        dfs(ans, nums, curr, i+1, n);
    }
};
