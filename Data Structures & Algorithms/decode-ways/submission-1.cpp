class Solution {
public:

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        return helper(s, n, 0, dp);
    }

    int helper(string &s, int n, int i, vector<int> &dp) {
        if(i >= n) return 1;
        if (s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        if(i+1 < n &&( s[i] == '1')|| (s[i] == '2' && s[i+1]-'0' <7 )){
            return dp[i] = helper(s, n, i+1, dp) + helper(s, n , i+2, dp);
        }
        return dp[i] = helper(s, n, i+1, dp);
    }
};
