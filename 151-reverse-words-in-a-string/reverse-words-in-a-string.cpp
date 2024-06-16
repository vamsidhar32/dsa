class Solution {
public:
    string reverseWords(string s) {
        
        string word="";
        cout<<word.size();
        stack<string>st ;
        for(int i = 0 ; i<s.size(); i++){ 

            if(s[i] != ' ') word += s[i];

            else if(s[i] == ' '){
                
                if(word.size())st.push(word);
                word = "";
            }
            
        }
        if(word.size())st.push(word);




        string ans = "";
        while(!st.empty()){
            //cout<<st.top() <<  endl;
            ans = ans+st.top()+" ";
            st.pop();
        }
        ans.pop_back();

        return ans ;
    }
};