class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(helperCircle(vector<int>(nums.begin(), nums.end() - 1)), helperCircle(vector<int> (nums.begin()+1, nums.end())));
    }

    int helperCircle(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(nums.size());
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2;i<n;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+ nums[i]);
        }
        return dp[n-1];
    }

    int helper(int n, int i, vector<int>& nums, vector<int> &dp) {
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        return dp[i] =  max(helper(n, i+1, nums,dp), nums[i]+helper(n, i+2, nums,dp));
    }
};
