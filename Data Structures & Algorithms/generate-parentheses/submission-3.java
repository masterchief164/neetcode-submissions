class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        dfs(n, "", 0, 0, ans);
        return ans;
    }

    public void dfs(int n, String tmp, int open, int close, List<String> ans) {
        // Base Case: If the string length is 2*n, we've formed a valid combination
        if (tmp.length() == n * 2) {
            ans.add(tmp);
            return;
        }

        // Branch 1: We can still add an open parenthesis
        if (open < n) {
            dfs(n, tmp + "(", open + 1, close, ans);
        }

        // Branch 2: We have more open parentheses than closed ones, so we can close one
        if (close < open) {
            dfs(n, tmp + ")", open, close + 1, ans);
        }
    }
}