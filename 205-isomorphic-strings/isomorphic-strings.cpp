class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp;
        unordered_set<char>st ;
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2) return false ;
        int i = 0 ; 

        while(i<n1){
            if(mpp.find(s[i]) == mpp.end()){
                if(st.find(t[i]) == st.end()){
                    mpp[s[i]] = t[i];
                    st.insert(t[i]);
                }
                else return false ;
                i++;
            }

            else{
                if(t[i] != mpp[s[i]]) return false ;
                else i++;
            }
            
        }

        return true ;
    }
};