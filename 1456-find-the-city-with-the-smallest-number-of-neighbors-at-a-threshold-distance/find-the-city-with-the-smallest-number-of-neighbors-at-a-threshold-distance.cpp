class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e8));
        for(int i = 0 ; i < n ; i++){
            matrix[i][i] = 0;
        }
        for(auto it :edges){
            int node1 = it[0];
            int node2 = it[1];
            int wt = it[2];
            matrix[node1][node2] = wt;
            matrix[node2][node1] = wt;
        }

        for(int via = 0 ; via <n ; via++){
        for(int i = 0 ; i <n ; i++){
            for(int j = 0 ; j<n; j++){
                if(matrix[i][via] != 1e8 && matrix[via][j] != 1e8){
                    if(matrix[i][via] + matrix[via][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][via] + matrix[j][via];
                    }
                }
            }
        }
        }

        int city = -1 ;
        int mincities = n+1;
        for(int i =0 ; i < n ; i++){
            int nucities=0 ;
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] <= distanceThreshold){
                    nucities++;
                }
            }
            if(nucities <= mincities){
                mincities = nucities;
                city = i ;
            } 
        }
        return city;

    }
};