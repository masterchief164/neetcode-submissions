class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = n*(n+1)/2;
        for(int i: nums) {
            ans-=i;
        }
        return ans;
    }
}
