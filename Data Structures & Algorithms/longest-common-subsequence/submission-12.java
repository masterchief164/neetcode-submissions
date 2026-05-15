class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length(), m = text2.length();
        int dp[][] = new int[n+1][m+1];

        for(int[] it: dp) {
            Arrays.fill(it, -1);
        }

        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i = 0;i<=m;i++) {
            dp[0][i] = 0;
        }

        for(int i = 1;i<=n;i++ ){
            for(int j = 1;j<=m;j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

        // return dfs(text1, text2, n,m,dp);
    }

    public int dfs(String a, String b, int i, int j, int[][]dp) {
        int n = a.length(), m = b.length();

        if(i == 0 || j == 0) return 0;

        if(dp[i][j] !=-1) return dp[i][j];

        if(a.charAt(i-1) == b.charAt(j-1)) {
            return dp[i][j] = 1 + dfs(a,b,i-1,j-1,dp);
        }

        return dp[i][j] = Math.max(dfs(a,b, i-1,j,dp), dfs(a,b,i,j-1,dp));
    }
}
