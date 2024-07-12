class Solution {
public:
    typedef pair<int,pair<int,int>> piii;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e8));
        ans[0][0] = grid[0][0];

        priority_queue<piii,vector<piii>,greater<piii>> pq;
        pq.push({grid[0][0],{0,0}});


        vector<int>delrow = {0,0,-1,1};
        vector<int>delcol = {-1,1,0,0};
        while(!pq.empty()){
            piii top = pq.top();
            pq.pop();
            int dist = top.first ;
            int row = top.second.first ;
            int col = top.second.second;

            //if(row == n-1 && col == n-1) return dist ;

            for(int k =0  ; k < 4 ; k++){
                int newrow = row+delrow[k];
                int newcol = col+delcol[k];
                if(newrow >=0 && newcol >=0 && newrow <n && newcol <m ){
                    int comp = max(dist,grid[newrow][newcol]);
                    if(comp < ans[newrow][newcol]){
                        ans[newrow][newcol] = comp ;
                        pq.push({comp,{newrow,newcol}});
                    }
                }
            }
        }

        return ans[n-1][n-1];
        
    }
};