class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n+m !=s3.size()) return 0;

        vector<vector<int>> dp (n+1, vector<int> (m+1, -1));

        return dfs(s1,s2,s3, 0,0,0, dp);
    }
    bool dfs(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp) {
        if(k == s3.size()) {
            return s1.size() == i && j == s2.size();
        }

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i<s1.size() && s1[i] == s3[k]) {
            if(dfs(s1,s2,s3, i+1,j,k+1, dp)) {
                return dp[i][j] = 1;
            }
        }

        if(j<s2.size() && s2[j] == s3[k]) {
            if(dfs(s1,s2,s3, i,j+1,k+1, dp)) {
                return dp[i][j] = 1;
            }
        }

        return dp[i][j] = 0;
    }
};
