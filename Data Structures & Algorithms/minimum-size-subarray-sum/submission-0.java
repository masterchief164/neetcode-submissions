class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int l = 0;
        int sum = 0;
        int ans = Integer.MAX_VALUE;

        for (int r = 0; r < n; r++) {
            sum += nums[r];
            
            while (sum >= target) {
                ans = Math.min(ans, r - l + 1); // Record the minimum length
                sum -= nums[l];                 // Shrink the sum
                l++;                            // Move the left pointer
            }
        }
        
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}