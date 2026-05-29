class Solution {
    public int minDistance(String s, String t) {
        int n = s.length(), m = t.length();

        int[][] dp = new int[n+1][m+1];
        for(int[] d: dp) {
            Arrays.fill(d, -1);
        }
        return dfs(0,0,s,t ,dp);
    }
    public int dfs(int i, int j, String s, String t, int[][] dp) {
        int n = s.length(), m = t.length();

        if(i == n) return m-j;
        if(j == m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s.charAt(i) == t.charAt(j)) {
            dp[i][j] = dfs(i+1,j+1, s,t, dp);
            return dp[i][j];
        }
        dp[i][j] = 1 + Math.min(Math.min(dfs(i+1,j, s,t, dp), dfs(i,j+1, s,t, dp)), dfs(i+1,j+1, s,t, dp));
        return dp[i][j];
    }
}
