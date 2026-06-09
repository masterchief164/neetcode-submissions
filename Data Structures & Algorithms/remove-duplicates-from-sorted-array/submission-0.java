class Solution {
    public int removeDuplicates(int[] nums) {
        int ans = 1 ,l = 0;
        for(int i = 1;i<nums.length;i++) {
            if(nums[i] != nums[l]) {
                l++;
                // ans++;
                nums[l] = nums[i];
            }
        }
        return l+1;
    }
}