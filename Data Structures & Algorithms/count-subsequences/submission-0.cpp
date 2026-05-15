class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) {
            return 0;
        }
        vector<vector<int>> dp (s.size()+1, vector<int> (t.size() +1, -1));
        return dfs(0,0,s,t, dp);
    }

    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j == t.size()) {
            return 1;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        if(i == s.size()) {
            return 0;
        }

        int ans = dfs(i+1, j, s,t, dp);

        if(s[i] == t[j]) {
            ans +=dfs(i+1, j+1, s, t, dp);
        }

        return dp[i][j] = ans;
    }
};
