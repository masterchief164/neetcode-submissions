class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (int)(l+r)/2.0;
            if(target == nums[mid]) return mid;

            if(nums[l] <= nums[mid]){
                if(nums[l] > target || nums[mid] < target){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if(target < nums[mid] || target > nums[r]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
