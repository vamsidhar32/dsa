class Solution {
public:
    void function(int index,vector<int>&temp,vector<int>& nums,vector<vector<int>>&ans,int n){

        if(index == n){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[index]);
        function(index+1,temp,nums,ans,n);

        temp.pop_back();

        function(index+1,temp,nums,ans,n);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        function(0,temp,nums,ans,nums.size());
        return ans ;
    }
};