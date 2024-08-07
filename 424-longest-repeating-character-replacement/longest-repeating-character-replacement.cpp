class Solution {
public:


    int update(unordered_map<char,int>&mpp){

        int ans = 0 ;
        for(auto it : mpp){
            ans = max(ans,it.second);
        }

        return ans ;
    }
    int characterReplacement(string s, int k) {

        int n = s.size();
        int i =0 ; 
        int j =0 ; 
        int ans = 0 ;

        unordered_map<char,int>mpp;
        int maxcount = 0 ;
        int count = 0 ;

        while( j < n){
            mpp[s[j]]++;
            count++;
            if(mpp[s[j]] > maxcount){
                maxcount = mpp[s[j]];
            }

            

            
                while((count - maxcount) > k){

                    
                    mpp[s[i]]--;
                    maxcount = update(mpp);
                    count--;
                    
                    i++;

                }
                


                if((count - maxcount) <=k){
                ans = max(ans,j-i+1);
                j++;
                }
            

        }

        return ans ;
    }
};