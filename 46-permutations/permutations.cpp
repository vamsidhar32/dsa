class Solution {
public:
    void func(vector<int>&temp , vector<vector<int>> &ans , vector<int>&nums,set<int>&st){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int i =0 ;i <nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                func(temp,ans,nums,st);
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans ;
        int n = nums.size();
        set<int>st;
        vector<int>temp;

        func(temp,ans,nums,st);
        return ans ;


    }
};