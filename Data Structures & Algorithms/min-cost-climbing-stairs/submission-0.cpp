class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        return min(dfs(0, n, dp, cost), dfs(1, n, dp, cost));
    }

    int dfs(int i, int n, vector<int> &dp, vector<int>& cost) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(dfs(i+1, n, dp, cost), dfs(i+2, n,dp,cost));
    }
};
