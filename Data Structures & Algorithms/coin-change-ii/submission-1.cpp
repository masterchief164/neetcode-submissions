class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size()+1,vector<int>(amount +1, -1));
        sort(coins.begin(), coins.end());
        return helper(amount, 0, coins.size(), coins, dp);
    }

    int helper(int amt, int i, int n, vector<int> &coins, vector<vector<int>> &dp) {
        if(amt == 0) return 1;

        if(i >= n) {
            return 0;
        }

        if(dp[i][amt] != -1) {
            return dp[i][amt];
        }

        int ans = 0;
        if(amt>=coins[i]){
            ans += helper(amt-coins[i], i, n, coins, dp);
            ans += helper(amt, i+1, n, coins, dp);
        }

        return dp[i][amt] = ans;
    }
};
