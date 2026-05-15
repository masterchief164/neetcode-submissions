class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return helper(dp, 0, n);
    }

    int helper(vector<int> &dp, int curr, int n) {
        if(curr == n) return 1;
        if(curr > n) return 0;
        if(dp[curr] != -1)
            return dp[curr];
        int ans = helper(dp, curr+1, n);
        ans+= helper(dp, curr+2,n);

        return dp[curr] = ans;
    }
};
