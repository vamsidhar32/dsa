class Disjointset{
    public:
    vector<int>parent,size;

    Disjointset (int n ){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i ;
        }
    }
    int findupar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findupar(parent[node]);

    }
    void unionbysize(int u , int v){
        int upu = findupar(u);
        int upv = findupar(v);
        if(upu == upv) return ;
        if(size[upu] > size[upv]){
            size[upu] += size[upv];
            parent[upv] = upu;
        }
        else{
            size[upv] += size[upu];
            parent[upu] = upv;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0 ;
        Disjointset ds(n*m);

        vector<int>delrow = {0,0,-1,1};
        vector<int>delcol = {-1,1,0,0};
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int row = i ;
                int col = j ;
                int node = row*m + col ;
                if(grid[row][col] ==1){
                    cnt++;
                for(int k = 0 ; k < 4 ; k++){
                    int newrow = row +delrow[k];
                    int newcol = col + delcol[k];
                    int adjnode = newrow*m +newcol;
                    if(newrow >=0 && newcol >= 0 && newrow <n && newcol <m){
                    if(grid[newrow][newcol] == 1 ){
                        ds.unionbysize(node,adjnode);
                    }
                    }
                }
                }
            }
        }
        int ans = 0 ;
        if(cnt == n*m) return cnt ;
        //cout << "Vamsi";
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                int row = i ; 
                int col = j ; 
                int node = row*m + col ;
                if(grid[row][col] == 0 ){
                    set<int>st;
                for(int k = 0 ; k <4 ; k++){
                    int newrow = row + delrow[k];
                    int newcol = col +delcol[k];
                    
                    if(newrow >=0 && newcol >=0 && newrow <n && newcol < m){
                    if(grid[newrow][newcol] == 1){
                        int adjnode = newrow*m + newcol ;
                        st.insert(ds.findupar(adjnode));
                    }
                    }
                }
                    int k = 0 ;
                    for(auto it :st){
                        k = k + ds.size[it];
                    }
                    ans = max(ans,k+1);

                }
                
                
            }
        }

        return ans;
    }
};