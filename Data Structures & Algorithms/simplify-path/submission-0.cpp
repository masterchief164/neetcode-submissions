class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string word;

        while(getline(ss, word, '/')) {
            if(!word.size() || word == ".") {
                continue;
            }
            else if(word == "..") {
                if(stk.size()) stk.pop();
            } else {
                stk.push(word);
            }
        }
        string ans = "";

        while(stk.size()){
            string word = stk.top();
            reverse(word.begin(), word.end());
            stk.pop();
            ans = ans + word + '/';
        }

        reverse(ans.begin(), ans.end());

        return ans.size()? ans : "/";
    }
};