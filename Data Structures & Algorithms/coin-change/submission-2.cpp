class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size(), m = amt;
        vector<vector<int>> dp (n+1, vector<int>(m+1, m+1));

        for(int i = 0;i<n+1;i++) {
            dp[i][0] = 0;
        }

        // for(int j = 0;j<m+1;j++) {
        //     if(j%coins[0] == 0)
        //         dp[1][j] = j/coins[0];
        // }

        for(int i = 1;i<n+1;i++) {
            for(int j = 1; j<m+1;j++) {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][amt] > amt ? -1: dp[n][amt] ;
    }
};
