class Solution {
public:
    int updatemax(map<char,int> &mpp){
        int ans = 0 ;
        for(auto it : mpp){
            ans = max(ans,it.second);
        }
        return ans ;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();

        int i = 0 ;
        int j = 0 ; 
        int maxi = 0 ;
        char store ;
        int ans = 0 ;
        int count = 0 ;
        map<char,int>mpp;

        while(j<n){

            mpp[s[j]]++;
            count++;
            if(mpp[s[j]] > maxi){
                maxi = mpp[s[j]];
                //store = s[j];
            }

            if(count - maxi <= k){
                ans =  max(ans,j-i+1);
                j++;
            } 

            else{
                while(count-maxi >k){
                    mpp[s[i]]--;
                    maxi = updatemax(mpp);
                    count--;
                    i++;
                }
                j++;
            }
            
        }

        return ans ;
    }
};