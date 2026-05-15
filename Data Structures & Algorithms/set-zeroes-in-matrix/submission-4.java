class Solution {
    public void setZeroes(int[][] matrix) {
        boolean top = false;
        int n = matrix.length, m = matrix[0].length;

        // for(int i = 0;i<n;i++) {
        //     top |= matrix[i][0];
        // }

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {

                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if(i > 0) {
                        matrix[i][0] = 0;
                    } else {
                        top = true;
                    }
                
                }
            }
        }

        for(int i = 1; i <n;i++) {
            for(int j = 1;j<m;j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int i = 0; i<n;i++) {
                matrix[i][0] = 0;
            }
        }

        if(top) {
            for(int i = 0;i<m;i++) {
                matrix[0][i] = 0;
            }
        }
    }
}
