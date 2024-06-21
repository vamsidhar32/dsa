class Solution {
public:
    int stoii(string s){
        int ans = 0 ;
        int i = s.size()-1;
        int j = 0 ;
        while(i >= 0  ){
            if(s[j++] == '1'){
                ans = ans + (1<<i);
                //cout <<ans << " " << i << "*" ;
            }
            i--;
        }
        return ans ;
    }
    void addone(string &s){
        int i = s.size()-1;
        while( i>=0 && s[i] != '0'){
            if(s[i] == '1'){
                s[i] ='0';
            }
            i--;
        }
        if(i == -1) {
            s.insert(s.begin(),'1');
        }
        else s[i] = '1';

        cout<<s <<endl ;
    }

    void divide(string &s){
        s.pop_back();
    }
    int numSteps(string s) {
        int ans = 0 ; 
        int n = s.size();
        //string str = "101929023r20000011111111";
        while(s.size() != 1){
            int n = s.size() ;
            if(s[n-1] == '1') addone(s);
            else if(s[n-1] == '0'){
                divide(s);
            }
            ans++;
        }
        
        return ans ;
    }
};