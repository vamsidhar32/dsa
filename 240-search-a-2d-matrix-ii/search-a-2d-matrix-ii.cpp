class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int i = m-1 ; // m-1 to 0 
        int j = 0; // 0 to n-1
 
        while(i >= 0 && j < n){
            if(target == matrix[i][j]) return true;
            else if(target < matrix[i][j]){
                i--;
            }

            else j++;
        }

        return false ;
    }
};