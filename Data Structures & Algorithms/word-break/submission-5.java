class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Map<Integer, Boolean> memo = new HashMap<>();

        memo.put(s.length(), true);

        return dfs(s, wordDict, memo, 0);
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
