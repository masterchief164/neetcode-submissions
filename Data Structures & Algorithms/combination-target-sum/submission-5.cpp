class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int>> ans;

        helper(0,0,target, nums, tmp, ans);

        return ans;

    }

    void helper(int i, int s, int tgt, vector<int> &nums, vector<int> tmp, vector<vector<int>> &ans) {
        if(s == tgt) {
            ans.push_back(tmp);
            return;
        }

        for(int j = i;j<nums.size(); j++) {
            if(s + nums[j] > tgt) {
                return;
            }

            tmp.push_back(nums[j]);
            helper(j, s+nums[j], tgt, nums, tmp, ans);
            tmp.pop_back();
        }
    }
};
