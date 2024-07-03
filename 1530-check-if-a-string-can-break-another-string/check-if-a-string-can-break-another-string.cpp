class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1.size() != s2.size()) return false ;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int i = 0 ;
        for(i = 0 ; i < s1.size(); i++ ){
            if(s2[i] >= s1[i]);
            else break;
        }
        
        if(i == s1.size()) return true ;

        
        i = 0 ;
        for(i = 0 ; i< s2.size(); i++){
            if(s1[i] >= s2[i]);
            else break;
        }

        if(i == s2.size()) return true ;
        return false ;

    }
};