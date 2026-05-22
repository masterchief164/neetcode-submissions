class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        dfs(n, "", 0,0,ans);
        return ans;
    }

    public void dfs(int n, String tmp, int open, int close, List<String> ans) {
        if(open < close || open+close >2*n || open > n) {
            return;
        }

        if(open + close == n*2 && open == close) {
            ans.add(tmp);
            return;
        }

        String tmp1 = tmp + '(';
        dfs(n , tmp1, open+1, close, ans);
        tmp1 = tmp + ')' ;
        dfs(n , tmp1, open, close+1, ans);
        return;
    }
}
