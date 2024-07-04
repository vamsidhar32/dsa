class Solution {
public:
    int maxi(int ind , string s , unordered_set<string> &st,string temp){
        if(ind == s.size() ) return 0;

        temp = temp+s[ind];

        int take = -1 ;
        int nottake = -1 ;
        if(st.find(temp) == st.end()){
            st.insert(temp);
            take = 1+maxi(ind+1,s,st,"");
            st.erase(temp);
        }
        nottake = maxi(ind+1,s,st,temp);

        return max(take,nottake);
    }
    int maxUniqueSplit(string s) {

        int n = s.size();
        //vector<int>dp(n+1,-1);
        unordered_set<string>st;
        string temp = "" ;
        return maxi(0,s,st,temp);
    }
};