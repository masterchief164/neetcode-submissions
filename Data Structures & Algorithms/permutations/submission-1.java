class Solution {
    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        
        dfs(nums, n - 1, ans);
        return ans;
    }

    private void dfs(int[] nums, int i, List<List<Integer>> ans) {
        if(i == 0) {
            List<Integer> currentPerm = new ArrayList<>();
            for(int num : nums) {
                currentPerm.add(num);
            }
            ans.add(currentPerm);
            return;
        }

        if(i < 0) return;

        for (int j = i; j >= 0; j--) {
            swap(nums, i, j);
            dfs(nums, i - 1, ans);
            swap(nums, i, j);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}