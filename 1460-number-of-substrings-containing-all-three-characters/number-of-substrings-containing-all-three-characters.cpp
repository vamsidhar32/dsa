class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0 ; 
        int j = 0 ;
        unordered_map<char,int> mpp;
        int count = 0 ;
        while(j <s.size()){
            mpp[s[j]]++;
            if(mpp.size() < 3) j++;

            if(mpp.size() == 3){
                while(mpp.size() == 3){
                    count += s.size()-j;
                    mpp[s[i]] --;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }

        return count ;
    }
};