class Disjointset{
    vector<int>parent,size;
    public:
        Disjointset(int n ){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i =0 ;i <=n ; i++){
                parent[i] = i ;
            }
        }

        int findupar(int node){
            if(parent[node] == node) return node ;
            return parent[node] =  findupar(parent[node]);
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
                parent[upu] = parent[upv];
                size[upv] += size[upu];
            }
        }
};

class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraedges = connections.size() - (n-1) ;
        Disjointset ds(n);
        int count = 0 ;
        for(auto it : connections){
            int node1 = it[0];
            int node2 = it[1];

            int upnode1 = ds.findupar(node1);
            int upnode2 = ds.findupar(node2);
            if(upnode1 == upnode2){
                count++;
                
            } 
            ds.unionbysize(node1,node2);
        }

        int comp = 0 ;
        for(int i = 0 ; i <n ; i++){
            if(ds.findupar(i) == i) comp++;
        }

        if( count  < comp-1 ) return -1 ;
        return comp-1;
    }
};