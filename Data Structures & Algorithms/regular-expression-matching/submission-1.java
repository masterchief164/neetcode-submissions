class Solution {
    public boolean isMatch(String s, String p) {
        Boolean[][] dp = new Boolean[s.length() + 1][p.length() + 1];
        return dfs(0, 0, s, p, dp);
    }

    private boolean dfs(int i, int j, String s, String p, Boolean[][] dp) {
        int n = s.length(), m = p.length();
        
        if (j == m) {
            return i == n;
        }

        if (dp[i][j] != null) return dp[i][j];

        boolean currentMatch = (i < n) && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');

        boolean result;

        if (j + 1 < m && p.charAt(j + 1) == '*') {
            result = dfs(i, j + 2, s, p, dp) || (currentMatch && dfs(i + 1, j, s, p, dp));
        } else {
            result = currentMatch && dfs(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = result;
    }
}