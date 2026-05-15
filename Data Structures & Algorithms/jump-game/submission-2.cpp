class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0, n = nums.size();

        for(int i = 0; i<n && i<=maxi;i++) {
            maxi =  max(i+nums[i], maxi);
        }

        return maxi >= n - 1;
    }
};
