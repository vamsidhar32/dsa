class Solution {
public:

    void func1(vector<int> &height , vector<int>&nsl){
        stack<pair<int,int>>st;
        vector<int>ans ;
        for(int i =0 ; i < height.size(); i++){
            
            while( !st.empty() && height[i] <= st.top().first){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top().second);
            st.push({height[i],i});
        }
        nsl = ans ;
    }


    void func2(vector<int> &height , vector<int>&nsr){
        stack<pair<int,int>>st;
        vector<int>ans ;
        int n = height.size();
        for(int i = n-1; i >= 0; i--){
            while( !st.empty() && height[i] <= st.top().first){
                st.pop();
            }
            if(st.empty()) ans.push_back(n);
            else ans.push_back(st.top().second);
            st.push({height[i],i});
        }
        reverse(ans.begin(),ans.end());
        nsr = ans ;
    }

    int largestRectangleArea(vector<int>& height) {
        int sum = -1 ;
        vector<int>nsl;
        vector<int>nsr;
        func1(height,nsl);
        func2(height,nsr);
        for(int i =0 ; i< height.size() ; i++){
            int l = nsl[i];
            int r = nsr[i];
            sum = max(sum,(r-l-1)*height[i]);

        }
        return sum ;
    }
};