class Solution {
    
    public void setZeroes(int[][] matrix) {
        // Lists to store the indices of rows and columns containing zero elements
        List<Integer> row = new ArrayList<>();
        List<Integer> col = new ArrayList();

        // Iterate through the matrix to find the zero elements and store their indices
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    row.add(i);
                    col.add(j);
                }
            }
        }

        // Iterate through the matrix again and set elements in rows and columns with zero elements to zero
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (row.contains(i) || col.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }

        // The function returns void (no specific return value is needed)
        return;
    }
}