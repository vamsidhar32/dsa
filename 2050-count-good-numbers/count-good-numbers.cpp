class Solution {
public:
    #define mod 1000000007 
    long long mypow(int x, long long even){

        if(even == 0) return 1 ;
        long long ans = mypow(x,even/2);
        
        if(even % 2 == 0) return (ans*ans)%mod ;

        return (ans * ans % mod * x % mod);

        
    }
    int countGoodNumbers(long long n) {
        if(n==0) return 0 ;
       long long even = n/2 + n%2 ;

       long long odd =  n/2 ;

        int ans = mypow(5,even)*mypow(4,odd) % mod;
        return ans ;
    }
};