class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        return helper(n, nums, 0, dp);
    }
    int helper(int &n, vector<int>&nums, int i, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = (max(helper(n, nums, i+2, dp)+nums[i], helper(n, nums, i+1, dp)));
    }
};
