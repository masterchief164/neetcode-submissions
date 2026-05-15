class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int l = 0, ans = 0;
        for(int i = 0;i<s.size(); i++){
            while(mp.find(s[i])!=mp.end()) {
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[i]);
            ans = max(ans,(int) mp.size());
        }
        return ans;
    }
};