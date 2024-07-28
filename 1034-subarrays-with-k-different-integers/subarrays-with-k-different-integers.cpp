class Solution {
public:


    int atmost(vector<int> &nums , int k ){
        if(k == -1) return 0 ;
        int i =0 ;
        int j =0;
        unordered_map<int,int>mpp;
        int n = nums.size();
        int count = 0 ;
        while(j < n ){
            mpp[nums[j]]++;

            if(mpp.size() <=k){
                count = count + (j-i+1);
                j++;
            }

            else if(mpp.size() > k){
                while(mpp.size() >k){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                    i++;
                }
                count = count + (j-i+1);
                j++;
            }
        }

        return count ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};