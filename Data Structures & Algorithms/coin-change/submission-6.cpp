class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), m = amount;

        vector<int> dp (m+1, m+1);

        dp[0] = 0;
        for(int i = 1;i<n+1;i++) {
            for(int j = 1;j<m+1;j++) {
                if(coins[i-1] <= j){
                    dp[j] = min(1+dp[j-coins[i-1]], dp[j]);
                // } else {
                    // dp[j] = dp[j];
                }
            }
        }
        return dp[m] == m+1 ? -1: dp[m];
    }
};

