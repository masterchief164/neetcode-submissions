class Solution {
    public int removeElement(int[] nums, int val) {
        int l = 0, n = nums.length;
        for(int r = 0;r<n;r++) {
            if(nums[r] != val) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
}