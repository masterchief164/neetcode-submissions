class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total %2) return 0;

        vector<vector<int>> dp(n+1, vector<int> (total/2+1, -1));

        // return dfs(nums, dp, 0, total/2);

        for(int i = 0;i<n+1;i++) {
            dp[i][0] = 1;
        }
        for(int j = 0;j<total/2+1;j++) {
            dp[0][j] = 0;
        }

        for(int i = 1;i<n+1;i++) {
            for(int j = 1;j<total/2+1;j++){
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][total/2];
    }

    bool dfs(vector<int> &nums, vector<vector<int>> &dp, int i, int tgt) {
        if(tgt == 0) return dp[i][tgt] = 1;
        if(tgt <0 || i >= nums.size()-1) return 0;
        if(dp[i][tgt] != -1) return dp[i][tgt];
        return dp[i][tgt] = dfs(nums, dp, i+1, tgt) || dfs(nums, dp, i+1, tgt - nums[i]);
    }
};
