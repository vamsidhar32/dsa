class Solution {
public:
    void func(int index, vector<int>& temp, int& sumtemp, vector<int>& candidates, int target, vector<vector<int>>& ans) {
        
        if (sumtemp == target) ans.push_back(temp);
        
        if (index == candidates.size()) {
            return;
        }

        

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // correctly skips duplicates
            // early exit if the sum exceeds target
            if (sumtemp > target) break;
            sumtemp += candidates[i];
            
            temp.push_back(candidates[i]);
            func(i + 1, temp, sumtemp, candidates, target, ans);
            temp.pop_back();
            sumtemp -= candidates[i];
        }
    
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // ensures the list is sorted to handle duplicates

        vector<vector<int>> ans;
        vector<int> temp;
        int sumtemp = 0;

        func(0, temp, sumtemp, candidates, target, ans);

        return ans;
    }
};
