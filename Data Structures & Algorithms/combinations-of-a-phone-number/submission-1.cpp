class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        string tmp;
        backtrack(0, tmp, digits);
        return res;
    }

    void backtrack(int i, string &curStr, string &digits) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            curStr +=c;
            backtrack(i + 1, curStr, digits);
            curStr.pop_back();
        }
    }
};