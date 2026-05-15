class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
       if(n <= 2) return n;

       dp[1] = 1;
       dp[2] = 2;

       for(int i = 3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
       }

       return dp[n];
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
