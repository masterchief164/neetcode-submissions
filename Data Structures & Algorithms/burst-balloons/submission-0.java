class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n+1][n+1];
        for(int[] d: dp) {
            Arrays.fill(d, -1);
        }
        return dfs(0, n-1, nums, dp);
    }

    private int dfs(int i, int j, int [] nums, int[][] dp) {
        int n = nums.length;
        // if(i>j || j >=n || i >=n|| i<0 || j < 0) return 0;

        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        for(int k = i;k<=j;k++) {
            int left = i-1 < 0 ? 1 : nums[i-1];
            int right = j+1>=n ? 1 : nums[j+1];
            ans = Math.max(ans, left*nums[k] *right + dfs(i, k-1, nums, dp) + dfs(k+1, j, nums, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
}
