class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);

        List<Integer> tmp = new ArrayList<>();
        dfs(candidates, target, candidates.length, tmp, ans);
        return ans;
    }

    private void dfs(int[] candidates, int target, int i, List<Integer> tmp, List<List<Integer>> ans) {
        if(i == 0 && target == 0) {
            ans.add(new ArrayList<>(tmp));
            return;
        }
        
        if(i < 1 || target <0)
            return;
        

        if(target>=candidates[i-1]){
            tmp.add(candidates[i-1]);
            dfs(candidates, target-candidates[i-1], i-1, tmp, ans);
            tmp.removeLast();
        }
        while( i > 1 && candidates[i-2]==candidates[i-1])
            i--;
        dfs(candidates, target, i-1, tmp, ans);
    }
}
