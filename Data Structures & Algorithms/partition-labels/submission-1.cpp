class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        vector<int> ans;
        int prev = -1, end = 0;

         for(int i = 0;i<s.size();i++) {
            freq[s[i]-'a'] = i;
        }

        for(int i = 0;i<s.size();i++) {
            // prev++;
            end = max(end, freq[s[i]-'a']);

            if(i == end) {
                ans.push_back(i-prev);
                prev = i;
            }
        }
        return ans;
    }
};
