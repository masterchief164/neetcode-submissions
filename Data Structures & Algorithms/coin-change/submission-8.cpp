class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), m = amount;

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

        vector<int> dp1(m+1, 1e9);

        dp1[0] = 0;

        // for(int i =0;i<=n;i++) {
        //     dp[i][0] = 0;
        // }

        // for(int i = 1;i<=n;i++) {
        //     for(int j = 1;j<=m;j++) {
        //         if(coins[i-1] <= j) {
        //             dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
        //         } else {
        //             dp[i][j]= dp[i-1][j];
        //         }
        //     }
        // }

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(coins[i-1] <= j) {
                    dp1[j] = min(dp1[j], 1+dp1[j-coins[i-1]]);
                }
            }
        }

        return dp1[m] != 1e9 ? dp1[m]:-1 ;

        // return dp[n][m] == 1e9 ? -1: dp[n][m];

        // dp[0] = 0;
        // for(int i = 1;i<n+1;i++) {
        //     for(int j = 1;j<m+1;j++) {
        //         if(coins[i-1] <= j){
        //             dp[j] = min(1+dp[j-coins[i-1]], dp[j]);
        //         // } else {
        //             // dp[j] = dp[j];
        //         }
        //     }
        // }
        // return dp[m] == m+1 ? -1: dp[m];

        // int ans = helper(dp, coins, m, n, n);
        // return ans == 1e9 ? -1: ans;
    }

    int helper(vector<vector<int>> &dp, vector<int> &coins, int amt, int n, int i) {
        if(amt == 0)
            return 0;
        if(i <= 0)
            return 1e9;

        if(dp[i][amt] != -1) return dp[i][amt];
        int ans = 0;
        if(coins[i-1] <= amt) ans = min(1+helper(dp, coins, amt-coins[i-1], n, i), helper(dp, coins, amt, n, i-1));
        else
            ans = helper(dp, coins, amt, n, i-1);
        return dp[i][amt] = ans;
        
    }
};

