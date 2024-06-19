class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0 ; 
        int j = 0 ;
        int flag =0;
        int ans = 0 ;
        map<char,int>mpp;

        while(j<n){
            mpp[s[j]]++;
            if(mpp[s[j]] == 2) flag = 1 ;

            if(flag == 0){
                ans = max(j-i+1,ans);
                j++;
            }
            else if(flag == 1){

                while(flag == 1){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 1) flag = 0 ;
                    i++;
                }
                mpp[s[j]]--;
            }


        }

        return ans ;
        
    }
};