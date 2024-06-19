class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0 ;
        int j = 0 ; 
        int n = s.size();
        int count = 0 ;

        map<char,int>mpp;

        while(j<n){
            mpp[s[j]]++ ;

            if(mpp.size()<3){
                j++;
            }

            else if(mpp.size()== 3){
                
                while(mpp.size() == 3){

                    count = count + (n-j) ;
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        
        }
        return count ;
    }
};