class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>strings;
        if(s.size() <=10) return {};
        set<string>st;
        int low =  0 ; 
        int high = 9 ;

        while(high < s.size()){
            
            if(st.find(s.substr(low,10)) != st.end()){
                strings.insert(s.substr(low,10));
            }
            else st.insert(s.substr(low,10));
            low++;
            high++;
        }
        vector<string>ans(strings.begin(),strings.end());
        return ans ;
    }
};