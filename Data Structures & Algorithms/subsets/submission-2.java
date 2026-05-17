class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<> ();
        List<Integer> tmp = new ArrayList<> ();

        dfs(nums, 0, tmp, ans);
        return ans;
    }

    private void dfs(int [] nums, int i, List<Integer> tmp, List<List<Integer>> ans) {
        if(i >= nums.length) {
            ans.add(new ArrayList(tmp));
            return;
        }

        tmp.add(nums[i]);
        dfs(nums, i+1, tmp, ans);
        tmp.remove(tmp.size() -1);
        dfs(nums, i+1, tmp, ans);
    }
}
