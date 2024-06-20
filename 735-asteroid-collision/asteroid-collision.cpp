class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i = 0 ; i < asteroids.size();i++){
            if(st.empty()) {
                st.push(asteroids[i]);
                continue;
            }
            if(asteroids[i] >=0){
                st.push(asteroids[i]);
            }
            else{
                if(st.top() > 0){
                    while(!st.empty() && abs(asteroids[i]) > st.top() && st.top() > 0){
                        st.pop();
                    }
                    if(st.empty()) st.push(asteroids[i]);
                    else if(st.top() <0) st.push(asteroids[i]);
                    else if(abs(asteroids[i]) == st.top()) st.pop();
                    else if(abs(asteroids[i]) < st.top()) ;
                }
                else{
                    st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};