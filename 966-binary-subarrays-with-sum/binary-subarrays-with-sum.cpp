class Solution {
public:

    int func(vector<int> & nums, int goal){
        if(goal == -1) return 0 ;
        int i =0  ;
        int j = 0 ;
        int sum =0 ;
        int count = 0 ;
        while( j< nums.size()){
            sum += nums[j];

            if(sum <= goal){
                count += j-i+1 ;
                j++;
            }
            else if(sum >goal){
                while(sum > goal){
                    sum -= nums[i];
                    i++;
                }
                count += j-i+1;
                j++;
            }
        }
        return count ;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal) - func(nums,goal-1);
    }
};