class Solution {
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return new ArrayList<>();
        Map<Character, String> mp = Map.of(
            '2', "abc",
            '3', "def",
            '4', "ghi",
            '5', "jkl",
            '6', "mno",
            '7', "pqrs",
            '8', "tuv",
            '9', "wxyz"
        );
        List<String> ans = new ArrayList<>();

        dfs(digits, 0, "", ans, mp);
        return ans;
    }

    private void dfs(String digits, int i, String tmp, List<String> ans, Map<Character, String> mp) {
        if(i > digits.length()) return;

        if(i == digits.length()) {
            ans.add(tmp);
            return;
        }
        for(char c: mp.get(digits.charAt(i)).toCharArray()) {
            dfs(digits, i+1, tmp+c, ans, mp);
        }
    }
}
