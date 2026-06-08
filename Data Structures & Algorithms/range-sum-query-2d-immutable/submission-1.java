class NumMatrix {
    private int[][] mat;
    public NumMatrix(int[][] matrix) {
        mat = new int[matrix.length][matrix[0].length];
        for(int i =0;i<matrix.length;i++){
            int res = 0;
            for(int j=0;j<matrix[0].length;j++){
                res = res + matrix[i][j];
                mat[i][j] = res;
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1;i<=row2;i++){
                if(col1>0){
                    ans = ans + mat[i][col2] - mat[i][col1-1];
                }
                else{
                    ans = ans + mat[i][col2];
                }
        }
        return ans;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */