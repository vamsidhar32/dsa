class Solution {
public:
    void func(int index, vector<int>&temp,vector<vector<int>>&ans ,int target, vector<int> & candidates){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        for(int i = index; i<candidates.size(); i++){

            if(i>index && candidates[i]== candidates[i-1]) continue;
            if(target < candidates[i]) break;
            temp.push_back(candidates[i]);
            func(i+1,temp,ans,target-candidates[i],candidates);
            temp.pop_back();
        }


    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());


        vector<vector<int>>ans;
        vector<int> temp;

        func(0,temp,ans,target,candidates);

        return ans ;
    }
};