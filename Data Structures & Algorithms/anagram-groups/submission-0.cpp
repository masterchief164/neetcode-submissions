class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(auto str: strs){
            vector<int> freq(26, 0);
            for(auto x: str){
                freq[x-'a']++;
            }
            string key = "";
            for(auto fre: freq){
                key += '.' + to_string(fre);
            }
            ans[key].push_back(str);
        }
        vector<vector<string>> sol;
        for(auto x: ans){
            sol.push_back(x.second);
        }
        return sol;
    }
};
