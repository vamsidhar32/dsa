class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0)) ;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vector<int>delrow{0,0,-1,1};
        vector<int>delcol{-1,1,0,0};
        queue<pair<int,int>>q;
        for(int i =0 ; i <n ; i++){
            for(int j =0 ; j <m ; j++){
                if(mat[i][j]== 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans[i][j] = 0 ;
                }
            }
        }
        int level = 0 ;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i = 0 ; i<size;i++ ){
                pair<int,int>p = q.front();
                q.pop();
                int row = p.first ;
                int col = p.second;

                for(int j = 0 ; j <4 ;j++){
                    int newrow = row+delrow[j];
                    int newcol = col+delcol[j];

                    if(newrow >=0 && newrow <n && newcol >=0 && newcol <m){
                    if(vis[newrow][newcol] == -1){
                        q.push({newrow,newcol});
                        vis[newrow][newcol] = 1 ;
                        ans[newrow][newcol] = level;
                    }
                    }
                }
            }
        }

        return ans ;
    }
};