class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        string del = "|";
        for(auto x: strs){
            enc += x + del;
        }
        return enc;
    }

    vector<string> decode(string s) {
        return split(s, '|');
    }
   
    vector<string> split(string str,char del){
        string s;
        stringstream ss(str);
        vector<string> v;
        while (getline(ss, s, del)) {
            v.push_back(s);
        }
        return v;
    }
};
