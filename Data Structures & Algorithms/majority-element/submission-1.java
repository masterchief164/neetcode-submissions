class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int elem = nums[0];
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (elem == nums[i]) count++;
            else count--;

            if (count == 0) {
                elem = nums[i];
                count = 1;
            }
        }

        return elem;
    }
}