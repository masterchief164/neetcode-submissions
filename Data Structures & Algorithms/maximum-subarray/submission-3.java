class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0, l = 0, r = 0, n = nums.length;
        int ans = nums[0];

        while(r<n){
            sum+=nums[r];
            ans = Math.max(ans, sum);
            if(sum <0) {
                sum = 0;
                l = r;
            } 
            r++;
        }
        return ans;
    }
}
