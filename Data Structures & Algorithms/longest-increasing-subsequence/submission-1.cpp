class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);

        int ans = 1;
        for(int i = 0;i<n;i++) {
            ans = max(ans, dfs(nums, dp, i));
        }
        return ans;
    }

    int dfs(vector<int>& nums, vector<int>& dp, int i) {
        if(dp[i] != -1) return dp[i];

        int ans = 1;

        for(int j = i+1;j<nums.size();j++) {
            if(nums[i] < nums[j])
                ans = max(ans,1+ dfs(nums, dp, j));
        }

        return dp[i] = ans;
    }
};
