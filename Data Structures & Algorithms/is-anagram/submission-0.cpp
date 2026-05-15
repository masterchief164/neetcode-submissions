class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return 0;
        }
        unordered_map<char, int> a, b;
        for(int i = 0;i<s.length();i++){
            a[s[i]]++;
            b[t[i]]++;
        }
        return a == b;
    }
};
