class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums.size(),0, nums,dp);
    }

    int helper(int n, int i, vector<int>& nums, vector<int> &dp) {
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        return dp[i] =  max(helper(n, i+1, nums,dp), nums[i]+helper(n, i+2, nums,dp));
    }
};
