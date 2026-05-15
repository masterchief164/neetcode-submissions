class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, ans = nums[0], n= nums.size();

        for(int i = 0;i<n;i++) {
            if(curr < 0) curr = 0;
            curr += nums[i];
            ans = max(curr, ans);

        }

        return ans;
    }
};
