class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, INT_MIN));
        return helper(nums, 0, 0, nums.size(), dp);
    }

    int helper(vector<int> &nums, int i, bool end, int n, vector<vector<int>> &dp) {
        if(i >= n) return end? 0: -1e6;
        if(dp[i][end] != INT_MIN) return dp[i][end]; 
        if(end) return dp[i][end] = max(0, nums[i] + helper(nums, i +1, 1, n, dp));

        return dp[i][end] = max(helper(nums, i + 1, 0, n, dp), nums[i] + helper(nums, i +1, 1, n, dp));
    }
};