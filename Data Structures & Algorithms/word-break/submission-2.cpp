class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> exist;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(auto x: wordDict) {
            exist[x] = 1;
        }
        return dfs(exist, 0, s.size(), s, dp);
    }

    bool dfs(unordered_map<string, bool> &exist, int i, int j, string &s, vector<vector<int>> &dp){
        string curr = s.substr(i, j-i+1);
        if(dp[i][j] != -1) return dp[i][j];
        
        if(exist[curr]) return dp[i][j] = 1;

        for(int k = i;k<j;k++) {
            if(dfs(exist, i, k, s, dp) && dfs(exist, k+1, j, s, dp)) return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
};
