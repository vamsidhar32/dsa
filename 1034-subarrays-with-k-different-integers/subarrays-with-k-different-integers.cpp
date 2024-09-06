class Solution {
public:

    int func(vector<int> &nums , int k){
        if(k == 0) return 0 ;
        int i =0 ; 
        int j = 0 ;
        int count = 0 ;
        unordered_map<int,int>mpp;

        while(j < nums.size()){
            mpp[nums[j]]++;

            if(mpp.size() <= k){
                count += j-i+1;
                j++;
            }
            else if(mpp.size() >k){
                while(mpp.size() >k){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                    i++;
                }
                count = count+ (j-i+1);
                j++;
            }
        }

        return count ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};