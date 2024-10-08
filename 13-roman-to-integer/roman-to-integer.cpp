class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
        mpp['I'] = 1 ;
        mpp['V'] = 5 ;
        mpp['X'] = 10 ;
        mpp['L'] = 50 ;
        mpp['C'] = 100 ;
        mpp['D'] = 500 ;
        mpp['M'] = 1000 ;

        int i = 0 ;
        int ans = 0 ;
        while(i < s.size()){
            if(mpp[s[i]] >= mpp[s[i+1]]){
                ans += mpp[s[i]];
                i++;
            }
            else{
                int k = 0 ;
                ans -= mpp[s[i]];
                ans += mpp[s[i+1]];
                i = i+2 ;
            }
        }
        return ans ;
    }
};