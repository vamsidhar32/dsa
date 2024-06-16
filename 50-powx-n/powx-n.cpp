class Solution {
public:
    double pow(double x,int n){
        if(n == 0) return 1 ;

        double y = pow(x,n/2);
        y = y*y;
        if( n % 2 == 0){
            return y;
        }
        else{
            return y*x;
        }
        //return 0;

    }
    double myPow(double x, int n) {
        double ans = 1;
        int k = 0 ;
        if(n<0) {
            n = abs(n);
            k = 1;
        }

        ans = pow(x,n);

        if(k == 1) return (1/ans);
        return ans ;
    }
};