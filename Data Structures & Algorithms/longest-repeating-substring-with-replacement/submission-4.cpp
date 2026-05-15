class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int l = 0, ans = 0;
        for(int i = 0;i<s.size(); i++){
            freq[s[i]]++;
            int ops = helper(freq);
            while(ops > k && l <= i){
                freq[s[l++]]--;
                ops = helper(freq);
            }
            ans = max(ans, i - l +1);
        }
        return ans;
    }
    int helper(unordered_map<char, int> &freq){
        int maxi = 0;
        int sum = 0;
        for(auto x: freq){
            maxi = max(maxi, x.second);
            sum+=x.second;
        }
        return sum - maxi;
    }
};
