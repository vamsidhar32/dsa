class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans ;

        unordered_map<string,vector<int>>mpp;

        for(int i = 0 ; i <strs.size();i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            mpp[st].push_back(i);
        }

        for(auto it : mpp){
            vector<string> v;
            for(auto it2 : it.second){
                v.push_back(strs[it2]);
            }
            ans.push_back(v);
        }

        return ans ;
    }
};