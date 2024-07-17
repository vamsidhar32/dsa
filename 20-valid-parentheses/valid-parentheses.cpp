class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push('a');
        map<char,char>mpp;
        mpp[')'] = '(';
        mpp['}'] = '{';
        mpp[']'] = '[';
        for(int i = 0 ; i <s.size(); i++){
            if(s[i] == '(' || s[i] == '{' ||s[i] == '[' )
                st.push(s[i]);
            else{
                if(st.top() == mpp[s[i]]) st.pop();
                else return false ;
            }
        }
        if(st.size() != 1) return false ;
        return true ;
    }
};