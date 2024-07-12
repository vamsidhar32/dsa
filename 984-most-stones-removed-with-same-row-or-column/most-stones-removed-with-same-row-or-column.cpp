class Disjointset{
    vector<int>parent,size;
    public:
        Disjointset(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0 ;i <= n ; i++){
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
                parent[upv] = upu;
                size[upu] += size[upv];
            }
            else{
                parent[upu] = upv;
                size[upv]+= size[upu];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        int maxrow = -1 ;
        int maxcol = -1;
        for(auto it :stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        Disjointset ds(maxrow + maxcol + 1);
        set<int>st;
        for(auto it :stones){
            int row = it[0];
            int col = it[1];
            int node1 = it[0];
            int node2 = maxrow + col + 1;
            ds.unionbysize(node1,node2);
            st.insert(node1);
            st.insert(node2);
        }
        int cnt = 0 ;
        for( auto it : st){
            if(ds.findupar(it) == it){
                cnt++;
            }
        }

        return n-(cnt);
        
    }
};