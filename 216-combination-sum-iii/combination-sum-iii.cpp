class Solution {
public:
    void func(int index,int &tempsum ,vector<int>&temp,vector<vector<int>>&ans,int k , int n,vector<int>&nums){
        if(tempsum >n) return ;
        if(index == nums.size() ){
            if(temp.size() == k && tempsum == n){
                ans.push_back(temp);
            }
            return;
        }

        tempsum += nums[index];
        temp.push_back(nums[index]);
        func(index+1,tempsum,temp,ans,k,n,nums);
        temp.pop_back();
        tempsum -= nums[index];
        func(index+1,tempsum,temp,ans,k,n,nums);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>temp ;
        int tempsum = 0 ; 
        func(0,tempsum,temp,ans,k,n,nums);
        return ans ;
    }
};