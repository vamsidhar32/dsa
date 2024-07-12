class Disjointset{
    vector<int>parent,size;
    public:
        Disjointset(int n ){
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i =0 ; i <=n ; i++) parent[i] = i ;
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
                size[upv] += size[upu];
            }
        }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //step1 ;

        
        
        int n = accounts.size();
        int m = accounts[0].size();

        Disjointset ds(n);


        unordered_map<string,int>mpp;
        for(int i = 0 ; i < n; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string str = accounts[i][j];
                if(mpp.find(str) != mpp.end()){
                    ds.unionbysize(mpp[str],i);
                }
                else mpp[str] = i ;
            }
        }
        //step2
        vector<string>acc[n];
        for(auto it : mpp){
            int node = it.second;
            string s = it.first ;
            acc[ds.findupar(node)].push_back(s);
        }

        //step3

        vector<vector<string>>ans;
        for(int i = 0 ; i< n; i++){
            vector<string>st;
            if(acc[i].size() == 0) continue;
            st.push_back(accounts[i][0]);
            for(int j =0 ; j < acc[i].size(); j++){
                st.push_back(acc[i][j]);
            }
            sort(st.begin()+1,st.end());
            ans.push_back(st);
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};