class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i =0 ; i< nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second > n/2) return it.first ;
        }
        return 0 ;
    }
};