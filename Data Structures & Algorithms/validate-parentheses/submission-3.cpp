class Solution {
public:
    bool isValid(string s) {
        int l = 0, r = s.size() -1;
        unordered_map<char, char> mp = {{'[', ']'},
         {'{', '}'},
         {'(', ')'}};
        stack<char> stk;
        for(auto x: s){
            if(!mp.count(x)){
                if(!stk.empty() && mp[stk.top()] == x) {
                    stk.pop();
                } else{
                    return false;
                }
            } else {
                stk.push(x);
            }
        }
        return stk.empty();
    }
};
