class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, n, dp);
    }

    bool helper(vector<int> nums, int i, int n, vector<int> &dp) {
        if(i == n-1) return 1;
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i]; 
        bool possible = 0;
        for(int j = 1;j<=nums[i]; j++){
            possible |= helper(nums, i + j, n, dp);
        }
        return dp[i] = possible;
    }
};
