class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return Math.min(dfs(0, cost.length, cost, dp), dfs(1, cost.length, cost, dp));
    }

    public int dfs(int i, int n, int[] cost, int[] dp) {
        if(i >=n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i] = cost[i] + Math.min(dfs(i+1, n, cost, dp), dfs(i+2, n, cost, dp));
    }
}
