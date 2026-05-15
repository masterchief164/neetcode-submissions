class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0);
    }
    int helper(vector<int> &nums, int amt, int i) {
        if(i == nums.size()) {
            return amt == 0 ? 1 : 0;
        }

        return helper(nums, amt - nums[i], i + 1) + helper(nums, amt + nums[i], i + 1);
    }
};
