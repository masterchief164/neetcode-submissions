class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // vector<int> dp(n, -1);
        // vector<int>tmp(nums.begin(), nums.end() - 1);
        // int ans = helper(n-1, n-2,tmp, dp);
        // dp = vector<int>(n, -1);
        // tmp = vector<int> (nums.begin()+1, nums.end());
        // ans = max(ans, helper(n-1, n-2, tmp, dp));
        int ans = helperCircle(vector<int>(nums.begin(), nums.end()-1));
        ans = max(ans, helperCircle(vector<int>(nums.begin()+1, nums.end())));
        return ans;
    }

    int helperCircle(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(nums.size()+1);
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2;i<=n;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+ nums[i-1]);
        }
        return dp[n];
    }

    int helper(int n, int i, vector<int>& nums, vector<int> &dp) {
        if(i <0) return 0;
        if(i == 0) return nums[0];

        if(dp[i] == -1) {
            return dp[i] = max(helper(n, i-1, nums, dp), nums[i] + helper(n, i-2, nums, dp));
        }
        return dp[i];

    }
};
