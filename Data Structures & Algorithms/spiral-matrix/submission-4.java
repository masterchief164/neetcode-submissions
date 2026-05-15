class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int t = 0, b = matrix.length, l = 0, r = matrix[0].length;

        List<Integer> ans = new ArrayList<>();
        while(l<r && t<b) {
            for(int i = l;i<r;i++) {
                ans.add(matrix[t][i]);
            }
            t++;
            for(int i = t; i<b;i++) {
                ans.add(matrix[i][r-1]);
            }
            r--;
            if(!(t<b && l<r))
                break;
            for(int i = r-1;i>=l;i--) {
                ans.add(matrix[b-1][i]);
            }
            b--;
            for(int i = b-1;i>=t;i--) {
                ans.add(matrix[i][l]);
            }
            l++;
        }

        return ans;
    }
}
