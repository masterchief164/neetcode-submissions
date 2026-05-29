class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        int[][] dp = new  int[n][m];
        for(int[] d: dp) {
            Arrays.fill(d,-1);
        }
        return dfs(0,0,s,t, dp);
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
