class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Map<Integer, Boolean> memo = new HashMap<>();

        boolean[] dp = new boolean[s.length()+1];

        dp[s.length()] = true;

        for(int i = s.length()-1;i>=0;i--) {
            for(String w: wordDict) {
                if(i+w.length() <=s.length() && s.substring(i, i+w.length()).equals(w)) {
                    dp[i] = dp[i+w.length()];
                }
                if(dp[i])
                    break;
            }
        }

        return dp[0];

        // memo.put(s.length(), true);

        // return dfs(s, wordDict, memo, 0);
    }

    boolean dfs(String s, List<String> words, Map<Integer, Boolean> memo, int i) {
        if(memo.containsKey(i)) {
            return memo.get(i);
        }

        for(String w: words) {
            if(i+w.length() <= s.length() && s.substring(i, i+w.length()).equals(w)) {
                if(dfs(s, words, memo, i+w.length())) {
                    memo.put(i, true);
                    return true;
                }
            }
        }
        memo.put(i, false);
        return false;
    }
}
