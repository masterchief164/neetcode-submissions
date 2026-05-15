class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        dfs(0, s, part, ans);
        return ans;
    }

    void dfs(int i, const string &s, vector<string> &part, vector<vector<string>> &ans) {
        int n = s.size();
        if(i>=n){
            ans.push_back(part);
            return;
        }

        for(int j = i;j<n;j++) {
            if(isPali(s, i, j)) {
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, part, ans);
                part.pop_back();
            }
        }
    }

    bool isPali(const string &s, int i, int j) {
        while(i<j) {
            if(s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};
