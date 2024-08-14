class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int flag = 0 ;
        while (1){
            if(s[i] == ' '){
                i++ ;
            }
            else break;
        }


        if(s[i] == '+' ){
            i++;
        }
        else if(s[i] == '-' ){
            flag = 1 ;
            i++;
        }
        double ans = 0 ;
        for(int j =  i ; j<s.length(); j++ ){
            if(s[i] < '0' || s[i] > '9'  ){
                break ;
            }
            int k = s[i] - '0' ;
            ans = ans*10 + k ;
            i++ ;




        }
        if(flag == 0 && ans <= 2147483647){
            return ans ;
            
        }
        else if(ans > 2147483647 && flag == 0 ) return 2147483647 ;


        if( flag == 1  && ans <= 2147483648){
            return 0 - ans ;
        }

        else if(ans > 2147483647 && flag == 1)  return 0 - 2147483648;


        return -1 ;


    }
};