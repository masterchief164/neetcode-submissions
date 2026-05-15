class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> vals;

        for(auto x: strs) {
            vector<int> freq(26,0);
            for(auto c: x) {
                freq[c-'a']++;
            }
            string key = "";
            for(int i = 0;i<26;i++) {
                key+= ',' + to_string(freq[i]);
            }
            vals[key].push_back(x);
        }

        vector<vector<string>> ans;

        for(auto x: vals) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
