class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0 ;
        int j = 0 ;
        stack<int> st;
        while(i < pushed.size() && j < popped.size()){
            if(st.empty()){
                st.push(pushed[i++]);
                continue;
            }
            else if(st.top() == popped[j]){
                st.pop();
                j++;
            }
            else st.push(pushed[i++]);
        }

        while(i <pushed.size() ){
            return true ;
        }
        while( j <popped.size()){
            if(st.top() == popped[j]){
                st.pop();
                j++;
            }
            else return false ;
        }

        if(st.empty()) return true ;
        return false ;
    }
};