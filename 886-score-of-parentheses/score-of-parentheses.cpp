class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0 ;
        int count = 0 ;
        int flag ;
        for(int i = 0 ; i <s.size();i++){
            if(s[i] == '(') {
                count++;
                flag = 1 ;
            }

            else if(s[i] == ')') {
                count--; 
                if(flag == 1){
                    ans = ans+ (1 << count) ;
                }
                
                flag = 0 ;
            }
        }

        return ans ;
    }
};