class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector< int>> dp (n+1, vector<int> (m+1, 0));
        vector<int> dp (m+1,0);

        for(int i = 1;i<n+1;i++) {
            int prevD = 0;
            for(int j =1; j<m+1;j++) {
                int tmp = dp[j];
                if(text1[i-1] == text2[j-1]) {
                    dp[j] =  1 + prevD;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prevD = tmp;
            }
        }
        return dp[m];
    
    }
};
