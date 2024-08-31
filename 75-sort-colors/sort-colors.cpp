class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0 ;
        int high = nums.size()-1;
        int low = 0 ;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;

            }

            else if(nums[mid] == 1){
                mid++;
            }

            else if(nums[mid] == 2){
                swap(nums[high],nums[mid]);
                high--;
            }
        }


    }
};