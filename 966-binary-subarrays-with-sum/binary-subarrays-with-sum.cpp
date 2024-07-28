class Solution {
public:

    int atmostgoal(vector<int>nums,int goal){
        int i =0 ; 
        int j =0 ; 
        int n = nums.size();
        int sum = 0 ;
        int count = 0;
        while(j < n){
            sum = sum+ nums[j];

            if(sum <= goal){
                count = count+(j-i+1);
                j++;
            }

            else if(sum >goal){
                while(sum > goal && i <= j){
                    sum = sum-nums[i];
                    i++;
                }
                if(sum <= goal)count = count + (j-i+1);
                j++;
            }
        }
        return count ;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostgoal(nums,goal) - atmostgoal(nums,goal-1);
    }
};