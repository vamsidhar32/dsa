class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false ;

        int i =0 ;
        unordered_map<char,char>mpp;
        unordered_map<char,char>mpp2;
        while(i < s.size()){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = t[i];
            }
            else{
                if(mpp[s[i]] != t[i]) return false ;
                if(mpp2[t[i]] != s[i]) return false ;
            }
            if(mpp2.find(t[i]) == mpp2.end()){
                mpp2[t[i]] = s[i];
            }
            else{
                if(mpp[s[i]] != t[i]) return false ;
                if(mpp2[t[i]] != s[i]) return false ;
            }
            i++;
        }

        return true ;
    }

};