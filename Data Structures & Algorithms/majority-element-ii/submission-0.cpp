class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto num: nums) {
            freq[num]++;

            if(freq.size() > 2) {
                unordered_map<int, int> newFreq;

                for(auto x: freq) {
                    if(x.second > 1) {
                        newFreq[x.first] = x.second -1;
                    }
                }
                freq = newFreq;
            }
        }
        vector<int> ans;
        for(auto x: freq) {
            int cnt = 0;
            for(int num: nums) {
                if(num == x.first)
                    cnt++;
            }
            if(cnt > nums.size()/3){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};