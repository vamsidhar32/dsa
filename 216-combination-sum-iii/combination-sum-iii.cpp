class Solution {
public:
    void func(int index,int sum ,vector<int>&temp,vector<vector<int>>&ans,int k,int n,vector<int>&nums){
        if(index == 10) return ;

        if(temp.size() == k && sum == n){
            ans.push_back(temp);
        }

        for(int i = index ; i < nums.size(); i++){
            sum += i+1;
            temp.push_back(i+1);
            func(i+1,sum,temp,ans,k,n,nums);
            temp.pop_back();
            sum-= i+1;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp ;
        int sum = 0 ;
        vector<int>nums = {1,2,3,4,5,6,7,8,9};

        func(0,sum,temp,ans,k,n,nums);

        return ans ;
    }
};