class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        vector<int> dp (n, -1);
        bool flag = 0;
        ans = max(ans, helper(n,nums, 0, dp, 1));
        dp = vector<int> (n, -1);
        ans = max(ans, helper(n,nums, 1, dp, 0));
        return ans;
    }
    int helper(int &n, vector<int>&nums, int i, vector<int> &dp, bool flag){
        if(i >= n) return 0;
        if(i == n-1 && flag) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = (max(helper(n, nums, i+2, dp, flag)+nums[i], helper(n, nums, i+1, dp, flag)));
    }
};
