class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false ;
        }

        int doop = x ;
        long ans = 0 ;
        while(x){
            int digit= x%10 ;
            ans = ans*10 + digit ;
            x = x/10 ;
        }

        if(doop == ans){
            return true;
        }
        return false ;
    }
};