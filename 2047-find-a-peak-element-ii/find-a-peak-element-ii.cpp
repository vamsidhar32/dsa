class Solution {
public:

    int func(vector<vector<int>> & mat, int mid, int n , int m ){
        int ele = INT_MIN;
        int ans = -1 ;
        for(int i = 0 ; i < n ; i++){
            if(ele < mat[i][mid]){
                ele = mat[i][mid];
                ans = i ;
            } 
        }

        return ans ;
    }
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0 ;
        int high = m -1 ;

        while(low <= high){
            int mid = low + (high - low)/2;
            int ans = func(matrix,mid,n,m);

            int left = mid-1 >=0 ? matrix[ans][mid-1] : -1;
            int right = mid+1 < m ? matrix[ans][mid+1] : -1;
            
            if( matrix[ans][mid] > left  && matrix[ans][mid] > right){
                return {ans,mid};
            }
            else if(left > matrix[ans][mid]) high = mid-1 ;
            else low =mid+ 1 ;
        }

        return {-1,-1};
    }
};