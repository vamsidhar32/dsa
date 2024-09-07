class Solution {
public:

    void func10(vector<int> &ans ,vector<int> &heights){
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

    void func20(vector<int>&ans,vector<int>heights){

        stack<int>st;
        for(int i = 0 ; i <heights.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push(heights[i]);

            }
            else if(heights[i] < st.top()){
                ans.push_back(st.top());
                //t.push(heights[i]);
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


    void func1(vector<int> &ngr , vector<int>&height){
        int maxi = -1 ;
        int n = height.size();
        for(int i =n-1 ;i >= 0 ; i--){
            ngr.push_back(maxi);
            maxi = max(maxi,height[i]);
        }
        reverse(ngr.begin(),ngr.end());
    }

    void func2(vector<int> &ngl , vector<int>&height){
        int maxi = -1 ;
        int n = height.size();
        for(int i = 0 ;i < n ; i++){
            ngl.push_back(maxi);
            maxi = max(maxi,height[i]);
        }

        //return ngl;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 ;
        int right = n-1;
        int leftmax = 0 ;
        int maxright = 0 ;
        int ans = 0 ;
        while(left <= right){
            if(height[left] <= height[right]){
                if(leftmax - height[left] >=0 ) ans += leftmax - height[left];
                leftmax = max(leftmax,height[left]);
                left++;
            }
            else{
                if(maxright - height[right] >=0 ) ans += maxright - height[right];
                maxright = max(maxright, height[right]);
                right--;
            }
        }

        return ans ;
    }
};