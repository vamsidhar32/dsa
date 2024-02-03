
class Solution {
private:
    string findprefix(string s1 , string s2){
        string ret ="";
        int n = min(s1.length(),s2.length());
        for(int i= 0;i<n;i++ ){
            if(s1[i] == s2[i]){
                ret.push_back(s1[i]);
            }
            else break;
        }
        return ret ;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longprefix = strs[0];
        string prefix ;
        for(int i= 0 ;i<strs.size();i++){
            prefix = findprefix(longprefix,strs[i]);
            longprefix = prefix ;

        }
        return longprefix;
        
    }
};