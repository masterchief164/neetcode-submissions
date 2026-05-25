class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        Arrays.sort(nums);

        for(int nu: nums) {
            sum+=nu;
        }

        if(sum%2 == 1) return false;
        boolean [][]dp = new boolean[n+1][sum/2+1];
        // return dfs(n, n, sum/2, nums, dp);

        for(int i = 0;i<=sum/2;i++) {
            dp[0][i] = false;
        }

        for(int i = 0;i<=n;i++) {
            dp[i][0] = true;
        }

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=sum/2;j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j]|| dp[i-1][j-nums[i-1]];
                } else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum/2];
    }

    private boolean dfs(int i, int n, int target, int[] nums, boolean [][]dp) {
        if(target == 0) return dp[i][target] = true;

        if(target < 0 || i < 0) return false;

        if(target>=nums[i])  {
            return dfs(i-1, n, target, nums, dp) || dfs(i-1, n, target - nums[i], nums ,dp);
        }
        return dfs(i-1, n, target, nums, dp);
    }
}
