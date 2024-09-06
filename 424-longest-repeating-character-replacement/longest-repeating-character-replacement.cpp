class Solution {
public:
    int update( unordered_map<char,int> mpp ){
        int ans = 0 ;

        for(auto it : mpp){
            ans = max(ans, it.second);
        }
        return ans ;
    }
    int characterReplacement(string s, int k) {
        int i =0 ; 
        int j =0 ;
        int ans = 0 ;
        unordered_map<char,int>mpp;
        int count = 0 ;
        int maxcount = 0 ;
        while(j < s.size()){
            mpp[s[j]]++;
            count++;

            if(mpp[s[j]] > maxcount){
                maxcount = mpp[s[j]];
            }

            if((count - maxcount) <= k){
                ans = max(ans , j-i+1);
                j++;
            }

            else if((count - maxcount) > k){
                while((count-maxcount) > k){
                    mpp[s[i]]--;
                    maxcount = update(mpp);
                    count--;
                    i++;
                }
                j++;
            }
        }

        return ans ;
    }
};