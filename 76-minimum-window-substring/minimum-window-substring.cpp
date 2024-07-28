class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() ;
        int i = 0 ;
        int j = 0 ;
        int ans = 1e9; 
        int first = 0 ;
        int second = 0;
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < t.size(); i++){
            mpp[t[i]]++;
        }
        int count = mpp.size();
        while(j < n){
            if(mpp.find(s[j]) != mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) count--;
            } 
            


            if(count > 0){
                j++;
            }
            else if(count == 0){
           
                while(count == 0){
                    if(j-i+1 < ans){
                        ans= j-i+1;
                        first = i ;
                        second = j;
                    }
                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]] == 1) count++;
                    }
                    i++;    
                }
                j++;
            }
        }

        if(ans == 1e9) return "";
        return s.substr(first , second-first+1);
    }
};