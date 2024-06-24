class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        int count =0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j <m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) count++;
            }
        }
        if(q.empty() && count) return -1;
        if(q.empty()) return 0 ;
        vector<int>delrow{0,0,-1,1};
        vector<int>delcol{-1,1,0,0};
        int time = 0 ;
        int count2 = 0 ;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i =0 ; i<size ; i++){
                pair<int,int>p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;

                for(int i = 0 ; i <4 ;i++){
                    int actrow = row+delrow[i];
                    int actcol = col+delcol[i];
                    if(actrow >=0 && actrow <n && actcol >=0 && actcol <m){
                        if(grid[actrow][actcol] == 1){
                            count2++;
                            grid[actrow][actcol] = 2;
                            q.push({actrow,actcol});

                        }
                    }
                }

            }
        }
        if(count != count2) return -1 ;
        return time-1;
    }
};