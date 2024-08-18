class Solution {
public:
    string prefixx(string s1, string s2){
        string ans = "";
        int i = 0 ;
        int n1 = s1.size();
        int n2 = s2.size();

        //if(n1 == 0 || n2 == 0 ) return ans;

        while(i< min(n1,n2)){
            if(s1[i] == s2[i]){
                ans = ans+s1[i];
            }
            else return ans ;
            i++;
        }
        return ans ;
    }
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];

        for(int i = 1 ; i<strs.size(); i++){
            prefix = prefixx(prefix,strs[i]);
        }
        return prefix;
    }
};