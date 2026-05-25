class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        // int[] dp = new int[n+1];
        // Arrays.fill(dp, -1);
        // return Math.min(dfs(0, cost.length, cost, dp), dfs(1, cost.length, cost, dp));

        for(int i = n-3;i>=0;i--) {
            cost[i] += Math.min(cost[i+1], cost[i+2]);
        }
        return Math.min(cost[0], cost[1]);
    }

    public int dfs(int i, int n, int[] cost, int[] dp) {
        if(i >=n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i] = cost[i] + Math.min(dfs(i+1, n, cost, dp), dfs(i+2, n, cost, dp));
    }
}
