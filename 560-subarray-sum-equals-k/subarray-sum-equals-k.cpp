class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        int presum = 0 ;
        unordered_map<int,int> mpp ;
        int count = 0 ;
        mpp[0] = 1 ;
        for(int i = 0 ; i < n ; i++){
            presum += nums[i] ;

            int rem = presum - k ; 
            

            count += mpp[rem];

            mpp[presum]++;
        }
        return count ;
    }
};