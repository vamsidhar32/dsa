class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0 ; 
        int j = 0 ;
        unordered_map<char,int>mpp;
        int flag = 0 ;

        int ans = 0 ;
        while( j < n){
            mpp[s[j]]++;
            if(mpp[s[j]] ==2) flag = 1 ;
            
            if(flag == 0){
                ans = max(ans,j-i+1);
                j++;
            } 
            else if(flag  ==1){
                while(flag == 1){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 1) flag = 0;
                    i++;
                }
                j++;
            }


        }

        return ans ;
    }
};