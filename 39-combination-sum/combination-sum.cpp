class Solution {
public:
    void func(int index,int &temp ,vector<int>&temp2 ,set<vector<int>>&ans , vector<int> &candidates,int target){
        if(target<0) return ;
        if(index == candidates.size()) {
            if(target == 0) ans.insert(temp2);
            return ;
        }

        target -= candidates[index];
        temp2.push_back(candidates[index]);
        func(index,temp,temp2,ans,candidates,target);

        target += candidates[index];
        temp2.pop_back();
        func(index+1,temp,temp2,ans,candidates,target);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        set<vector<int>>ans;
        vector<int>temp2 ;
        int temp = 0;
        func(0,temp ,temp2,ans,candidates,target);
        vector<vector<int>>mainans;

        for(auto it :ans){
            mainans.push_back(it);
        }

        return mainans;

    }
};