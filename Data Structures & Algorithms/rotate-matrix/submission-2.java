class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        for(int i = 0;i<n/2;i++) {
            int[] tmp = matrix[i];
            matrix[i] = matrix[n-1-i];
            matrix[n-1-i] = tmp;
            // swap(matrix[i], matrix[n-1-i]);
        }

        for(int i = 0;i<n;i++) {
            for(int j = i;j<m;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}
