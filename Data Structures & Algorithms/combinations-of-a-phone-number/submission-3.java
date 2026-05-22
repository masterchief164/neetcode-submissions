class Solution {
    // 1. Static array mapping allocated exactly once
    private static final String[] KEYPAD = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new ArrayList<>();
        
        List<String> ans = new ArrayList<>();
        // 2. Pass a StringBuilder instead of an immutable String
        dfs(digits, 0, new StringBuilder(), ans);
        return ans;
    }

    private void dfs(String digits, int i, StringBuilder tmp, List<String> ans) {
        if (i == digits.length()) {
            ans.add(tmp.toString());
            return;
        }
        
        // Convert char to int index (e.g., '2' - '0' = 2)
        String letters = KEYPAD[digits.charAt(i) - '0'];
        
        for (char c : letters.toCharArray()) {
            tmp.append(c);                    // Add character
            dfs(digits, i + 1, tmp, ans);     // Recurse
            tmp.deleteCharAt(tmp.length() - 1); // BACKTRACK: Remove character
        }
    }
}