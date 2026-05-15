class Solution {
public:
    int numDecodings(string s) {
        // unordered_map<int, int> dp;
        int n = s.size();
        vector<int> dp(n+1,-1);
        // dp[s.size()] = 1;
        // for(int i = n-1;i>=0;i--) {
        //     if(s[i] == '0')
        //         dp[i] = 0;
        //     else {
        //         dp[i] = dp[i+1];
        //         if(i+1<n && (s[i] == '1' || (s[i]=='2' && s[i+1] <= '6'))){
        //             dp[i] += dp[i+2];
        //         }
        //     }
        // }
        // return dp[0];
        return helper(dp, s, n);
    }

private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' ||
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }

    int helper(vector<int> &dp, string &s, int i) {
        if(i < 0) return 0;
        if(i == 0) return 1;

        if(i == 1) return s[0] == '0' ? 0: 1;

        int ans = 0;
        if(dp[i] != -1) {
            return dp[i];
        }
        if(s[i-1] != '0') {
            ans+=helper(dp, s, i-1);
        }

        if (i >= 2) {
            int last = stoi(s.substr(i-2, 2));
            if(last < 27 && last > 9) {
                ans += helper(dp, s, i-2);
            }
        }

        return dp[i] = ans;
    }
};