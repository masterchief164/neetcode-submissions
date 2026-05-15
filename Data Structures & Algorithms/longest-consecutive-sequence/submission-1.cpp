class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> val;
        int ans= 0;

        for(auto x: nums){
            if(!val[x]){ // if x doesn't exist
                val[x] = val[x-1] + val[x+1] +1;
                val[x - val[x-1]] = val[x];
                val[x + val[x+1]] = val[x];
                ans = max(ans, val[x]);
            }
        }
        return ans;
    }
};
