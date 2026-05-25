public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) return 0;

        int held = -prices[0]; // dp[i-1][1]
        int notHeld = 0;       // dp[i-1][0]
        int notHeldPrev = 0;   // dp[i-2][0]

        for (int i = 1; i < prices.length; i++) {
            int nextNotHeld = Math.max(notHeld, held + prices[i]);
            int nextHeld = Math.max(held, notHeldPrev - prices[i]);
            
            // Shift variables forward for the next day's iteration
            notHeldPrev = notHeld;
            notHeld = nextNotHeld;
            held = nextHeld;
        }

        return notHeld;
    }
}