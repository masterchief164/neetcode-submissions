class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(0, 0, n, curr, ans);
        return ans;
    }

    void helper(int o, int c, int n, string curr, vector<string> &ans) {
        if(c == o && o == n) {
            ans.push_back(curr);
            return;
        }

        if(o < n) {
            curr+='(';
            helper(o+1, c, n, curr, ans);
            curr.pop_back();
        }

        if(c < o) {
            curr+=')';
            helper(o, c+1, n, curr, ans);
            curr.pop_back();
        }
    }
};
