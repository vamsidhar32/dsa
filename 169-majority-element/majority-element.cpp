class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ; 
        int ele ;
        for(int i =0 ; i< nums.size() ; i++){
            if(count == 0) ele = nums[i];

            if(nums[i] != ele) count--;
            else count++;
        }

        return ele;

    }
};