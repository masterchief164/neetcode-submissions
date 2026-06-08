class NumMatrix {
    private int[][] pre;
    private int n,m;
    public NumMatrix(int[][] matrix) {
        n = matrix.length;
        m = matrix[0].length;
        pre = new int[n+1][m+1];
        for(int i = 0;i<n;i++) {
            int pref = 0;
            for(int j = 0; j<m;j++) {
                pref += matrix[i][j];
                int top = pre[i][j+1];
                pre[i+1][j+1] += pref + top;
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        // Calculate the four points based on the Inclusion-Exclusion principle
        int bottomRight = pre[row2 + 1][col2 + 1];
        int above = pre[row1][col2 + 1];
        int left = pre[row2 + 1][col1];
        int topLeft = pre[row1][col1];

        return bottomRight - above - left + topLeft;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */