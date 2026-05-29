class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        int[][] dp = new  int[n+1][m+1];
        for(int i = 0;i<=n;i++) {
            dp[i][0] = 1;
        }

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(s.charAt(i-1) == t.charAt(j-1)) {
                    dp[i][j] += dp[i-1][j-1];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[n][m];
        // return dfs(0,0,s,t, dp);
    }

    public int dfs(int i, int j, String s, String t, int[][] dp) {
        int n = s.length(), m = t.length();
        if(j>=m) {
            return 1;
        }
        if(i>=n){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(s.charAt(i) == t.charAt(j)){
            ans+=dfs(i+1, j+1,s,t, dp);
        }
        ans += dfs(i+1, j, s, t, dp);

        dp[i][j] = ans;
        return ans;
    }
}
