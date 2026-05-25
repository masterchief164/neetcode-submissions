class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int [][]dp = new int[n+1][2];

        dp[0][1] = -prices[0];
        dp[0][0] = 0;

        for(int i = 1;i<n;i++) {
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1]+prices[i]);

            int prevProfit = (i >= 2) ? dp[i - 2][0] : 0;
            dp[i][1] = Math.max(dp[i - 1][1], prevProfit - prices[i]);
        }
        return dp[n-1][0];
    }
}
