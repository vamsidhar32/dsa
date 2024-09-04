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

        int ans = 0 ;
        int i = 0;
        while(i<s.size() -1){
            if(mpp[s[i]] >= mpp[s[i+1]]){
                ans += mpp[s[i]];
                i++;
            }
            else {
                int k = 0 ;
                k += mpp[s[i+1]];
                k -= mpp[s[i]];
                ans += k ;
                i = i+2;

            }
            cout << ans << " " << i <<  " " ; 
        }
        if(i == s.size() -1){
            ans += mpp[s[i]];
        }

        return ans ;
    }
};