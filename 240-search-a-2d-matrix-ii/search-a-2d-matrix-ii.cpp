class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0 ;
        int j = m-1 ;

        while(j >=0 && i <n){
            if(matrix[i][j] == target) return true ;
            else if(matrix[i][j] > target) j--;
            else if(matrix[i][j] < target) i++;
        }
        return false ;
    }
};