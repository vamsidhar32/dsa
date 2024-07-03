class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mpp;
        if(k>s.size()) return false ;
        for(int i = 0 ; i <s.size();i++){
            mpp[s[i]]++;
        }
        int odd = 0 ;
        for(auto it :mpp ){
            if(it.second % 2 == 1) odd++;
        }

        if(odd <= k) return true ;
        return false ;
    }
};