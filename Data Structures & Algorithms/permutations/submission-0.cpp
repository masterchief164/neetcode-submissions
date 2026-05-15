class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, ans, 0, nums.size());
        return ans;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &ans, int i, int n) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }

        for(int j = i;j<n;j++) {
            swap(nums[i], nums[j]);
            dfs(nums, ans, i+1, n);
            swap(nums[i], nums[j]);
        }
    }
};
