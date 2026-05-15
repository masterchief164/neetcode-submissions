class Solution {
public:
    string decodeString(string s) {
        stack<string> strStk;
        stack<int> numStk;

        int k = 0;
        string curr = "";

        for(auto c: s) {
            if(isdigit(c)){
                k = 10*k+(c-'0');
            } else if (c == '['){
                numStk.push(k);
                strStk.push(curr);
                k =0;
                curr = "";
            } else if(c == ']') {
                int rep = numStk.top();
                numStk.pop();
                string str = strStk.top();
                strStk.pop();
                string tmp= "";
                for(int i = 0;i<rep;i++) {
                    tmp = tmp + curr;
                }
                curr = str + tmp;
            } else { 
                curr+=c;
            }
        }
        return curr;
    }
};