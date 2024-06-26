class Solution {
public:
    typedef pair<int,pair<int,int>> piii ;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();


        vector<vector<int>>ans(n,(vector<int>(m,1e9)));
        ans[0][0] = 0 ;

        priority_queue<piii,vector<piii>,greater<piii>>pq;
        pq.push({0,{0,0}});

        vector<int>delrow = {0,0,-1,1};
        vector<int>delcol = {-1,1,0,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0 ; i <4;i++){
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                if(newrow>=0 && newrow<n && newcol >=0 && newcol <m){
                    int comp = max(dist , abs(heights[newrow][newcol] - heights[row][col]));
                    if(comp < ans[newrow][newcol]){
                        ans[newrow][newcol] = comp;
                        pq.push({comp,{newrow,newcol}});
                    }   
                }
            }
        }

        if(ans[n-1][m-1] == 1e9) return -1;
        return ans[n-1][m-1];
    }
};