class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int n = nums.size();
        if(lb == n) return {-1,-1};
        if(nums[lb] != target) return {-1,-1};

        int ub = lb;
        while(ub < n- 1 && nums[ub] == nums[ub+1]){
            ub = ub+1;
            if(ub == n-1) break;
        }

        return {lb,ub};
    }
};