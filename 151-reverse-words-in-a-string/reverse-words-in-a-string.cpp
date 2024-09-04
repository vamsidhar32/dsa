class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        string ans = "";
        for(int i = n-1 ; i >= 0 ; i--){

            if(s[i] == ' '){
                if(temp.size() == 0) continue;
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans.push_back(' ');
                temp = "";
            }

            else temp += s[i];
        }
        
        if(temp.size() !=0){
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans.push_back(' ');
            temp = ' ';
        }
        ans.pop_back();
        return ans ;
    }
};