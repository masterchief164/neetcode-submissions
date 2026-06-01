class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int ans[] = new int[3];
        for(int[] trip: triplets) {
            if(trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) continue;

            ans[0] = Math.max(ans[0], trip[0]);
            ans[1] = Math.max(ans[1], trip[1]);
            ans[2] = Math.max(ans[2], trip[2]);
        }

        return Arrays.equals(ans, target);
    }
}
