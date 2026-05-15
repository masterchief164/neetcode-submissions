class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount +1, -1);
        int ans = helper(coins, amount, dp);
        return ans >= 1e9 ? -1: ans;
    }
    int helper(vector<int> &coins, int amt, vector<int> &dp) {

        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        
        int ans = 1e9;

        for(auto coin: coins) {
            if(amt - coin >= 0) {
                int tmp = helper(coins, amt - coin, dp);
                if(tmp <= 1e9)
                    ans = min(ans, 1 + tmp);
            }
        }
        return dp[amt] = ans;
    }
};
