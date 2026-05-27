class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m ) return false;
        Boolean[][] dp = new Boolean[n+1][m+1];

        return dfs(s1,s2,s3,0,0,0,dp);
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
