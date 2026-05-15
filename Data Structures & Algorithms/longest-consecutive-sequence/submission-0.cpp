class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vals(nums.begin(), nums.end());
        int ans= 0;

        for(auto x: nums){
            if(vals.find(x-1) == vals.end()){
                int curr = 1;
                while(vals.find(x+curr) != vals.end()){
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
