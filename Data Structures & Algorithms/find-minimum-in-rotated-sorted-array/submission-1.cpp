class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;
        while(l<=r){
            if(nums[l] < nums[r]){
                ans = min(ans, nums[l]);
                break;
            }
            int m = (int)((l+r)/2);
            ans = min(ans, nums[m]);
            if(nums[l] <= nums[m]){
                l = m +1;
            } else{
                r = m-1;
            }
        }
        return ans;
    }
};
