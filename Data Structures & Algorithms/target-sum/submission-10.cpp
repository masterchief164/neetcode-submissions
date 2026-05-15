class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int amt) {
        unordered_map<int, int> dp;

        dp[0] = 1;

        for(int num: nums) {
            unordered_map<int, int> newDp;
            for(auto x: dp) {
                newDp[x.first-num] +=x.second;
                newDp[x.first+num] +=x.second;
            }
            dp = newDp;
        }
        return dp[amt];
    }
};
