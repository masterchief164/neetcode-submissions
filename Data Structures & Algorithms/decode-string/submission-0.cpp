class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        for(auto c: s) {
            if(c != ']') {
                stk.push(string(1, c));
            } else {
                string sub = "";
                while(stk.top()!="[") {
                    sub = stk.top() + sub;
                    stk.pop();
                }
                stk.pop();
                string num = "";
                while(stk.size() && isdigit(stk.top()[0])) {
                    num = stk.top() + num;
                    stk.pop();
                }

                int rep = stoi(num);

                string tmp = "";
                for(int i =0;i<rep;i++){
                    tmp = tmp+sub;
                }
                stk.push(tmp);
            }
        }
        string ans = "";

        while(stk.size()){
            ans = stk.top()+ ans;
            stk.pop();
        }
        return ans;
    }
};