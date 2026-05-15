class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0];
        int pre = 0;
        int suf = 0;
        int n = nums.length;

        for(int i = 0;i<n;i++) {
            pre = (pre == 0? 1 : pre)*nums[i];
            suf = (suf == 0? 1 : suf) * nums[n-1-i];

            ans = Math.max(ans, Math.max(pre, suf));
        }
        return ans;
    }
}
