class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> reverse_index(nums.size() + 1);
        
        for(auto x: nums){
            freq[x]++;
        }

        for(auto val: freq){
            reverse_index[val.second].push_back(val.first);
        }

        vector<int> ans;
        for(int i = nums.size();i>0;i--){
            for(auto val: reverse_index[i]){
                if(ans.size() == k)
                    break;
                ans.push_back(val);
            }
        }
        return ans;
    }
};
