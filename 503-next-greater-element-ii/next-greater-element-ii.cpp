class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans ;
        int n = nums.size();

        stack<int>st;

        for(int i = 2*n-1 ; i >= 0 ;i--){
            if(!st.empty() && nums[i%n] < st.top()){
                if(i<n) ans.push_back(st.top());
                st.push(nums[i%n]);
            }
            else{
                while(!st.empty() && nums[i%n] >= st.top()){
                    st.pop();
                }
                if(st.empty() && i<n) ans.push_back(-1);
                else if(i<n) ans.push_back(st.top());

                st.push(nums[i%n]);
            }
        }

        reverse(ans.begin(),ans.end());

        return ans ;
    }
};