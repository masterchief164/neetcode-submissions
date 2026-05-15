class Solution {
    public boolean canJump(int[] nums) {
        // int maxReach = 0, n = nums.length;
        // for(int i =0;i<n;i++) {
        //     if(maxReach < i) {
        //         return false;
        //     }
        //     maxReach = Math.max(maxReach, i+nums[i]);
        // }

        // return maxReach >= n-1;
        HashMap<Integer, Boolean> dp = new HashMap<Integer, Boolean>();
        int n = nums.length;

        return dfs(nums, 0, n, dp);
    }

    boolean dfs(int[] nums, int i, int n, HashMap<Integer, Boolean> dp) {
        if(i >= n-1) {
            dp.put(i, true);
            return true;
        }

        if(dp.containsKey(i)) {
            return dp.get(i);
        }

        boolean ans = false;
        for(int j = i+1;j<=i+nums[i];j++) {
            ans |= dfs(nums, j, n, dp);
        }

        dp.put(i, ans);
        return ans;
    }
}
