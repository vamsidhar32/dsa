class Solution {
public:

    void func1(vector<int> &ans ,vector<int> &heights){
        stack<int>st;

        for(int i =heights.size()-1 ; i>=0 ;i--){
            if(st.empty()){
                ans.push_back(-1);
                st.push(heights[i]);
                continue;
            }
            else if(heights[i] < st.top()){
                ans.push_back(st.top());
                //st.push(heights[i]);
            }
            else {
                while(!st.empty() && heights[i] >= st.top()){
                    st.pop();
                }
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
                st.push(heights[i]);
            }

        }
        reverse(ans.begin(),ans.end());
    }

    void func2(vector<int>&ans,vector<int>heights){

        stack<int>st;
        for(int i = 0 ; i <heights.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push(heights[i]);

            }
            else if(heights[i] < st.top()){
                ans.push_back(st.top());
                //st.push(heights[i]);
            }
            else{
                while(!st.empty() && heights[i] >= st.top()){
                    st.pop();
                }
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
                st.push(heights[i]);
            }
        }
    }
    int trap(vector<int>& height) {
        
        vector<int>ngr;
        vector<int>ngl;
        func1(ngr,height);
        func2(ngl,height);

        // for(int i = 0 ;i<height.size(); i++){
        //     cout<<ngr[i] << " " ;
        // }
        // cout <<endl;
        // for(int i = 0 ;i<height.size(); i++){
        //     cout<<ngl[i] << " " ;
        // }

        int ans = 0 ;

        for(int i = 0 ;i <height.size(); i++){
            int k = min(ngl[i] ,ngr[i]);
            if(k<0) continue ;
            ans = ans + k - height[i];
        }


        return ans ;
    }
};