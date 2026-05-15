class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return helper(nums, 0, -1, n, dp);
    }
    int helper(vector<int> &nums, int i, int j, int &n, vector<vector<int>> &dp) {
        if(i>=n) return 0;
        if(j > -1 && dp[i][j+1] != -1) return dp[i][j+1];
        int notTake = helper(nums, i+1, j, n, dp);
        int take = INT_MIN;
        if(j == -1 || nums[i] > nums[j]) take = 1+helper(nums, i+1, i, n, dp);
        return dp[i][j+1] = max(take, notTake);
    }
};
