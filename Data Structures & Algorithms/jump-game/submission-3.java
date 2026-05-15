class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = 0, n = nums.length;
        for(int i =0;i<n;i++) {
            if(maxReach < i) {
                return false;
            }
            maxReach = Math.max(maxReach, i+nums[i]);
        }

        return maxReach >= n-1;
    }
}
