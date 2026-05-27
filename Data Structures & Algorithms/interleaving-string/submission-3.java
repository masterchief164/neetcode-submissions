class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m ) return false;
        // Boolean[][] dp = new Boolean[n+1][m+1];
        boolean[][] dp = new boolean[n + 1][m + 1];

        dp[0][0] = true;

        for(int i =0;i<=n;i++) {
            for(int j = 0;j<=m;j++) {
                if(i == 0 && j== 0) 
                    continue;
                if(i> 0 && s1.charAt(i-1) == s3.charAt(i+j-1))
                    dp[i][j] |= dp[i-1][j];
                if(j>0 && s2.charAt(j-1) == s3.charAt(i+j-1))
                    dp[i][j] |= dp[i][j-1];
            }
        }

        return dp[n][m];
        // return dfs(s1,s2,s3,0,0,0,dp);
    }

    private boolean dfs(String s1, String s2, String s3, int i, int j , int k, Boolean[][]dp) {
        int n = s1.length(), m = s2.length();
        if(k == s3.length()) {
            return (i==n)&&(j==m);
        }

        if(dp[i][j] != null) {
            return dp[i][j];
        }

        boolean res = false;
        if(i<n &&s1.charAt(i) == s3.charAt(k))
            res = dfs(s1,s2,s3,i+1,j,k+1,dp);
        if(!res && j<m && s2.charAt(j) == s3.charAt(k))
            res = dfs(s1,s2,s3,i,j+1,k+1,dp);
        
        dp[i][j] = res;
        return res;
    }
}
