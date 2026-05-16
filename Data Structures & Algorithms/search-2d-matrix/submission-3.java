class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int n = matrix.length;      // Number of rows
        int m = matrix[0].length;   // Number of columns

        int l = 0;
        int r = (n * m) - 1;        // Total elements - 1

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // Map 1D index back to 2D matrix coordinates
            int row = mid / m;
            int col = mid % m;
            int val = matrix[row][col];

            if (val == target) {
                return true;
            } else if (val < target) {
                l = mid + 1; // Target is in the right half
            } else {
                r = mid - 1; // Target is in the left half
            }
        }

        return false;
    }
}