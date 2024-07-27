class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size() ;
        int mini = INT_MAX;

        if(n==0) return -1;

        int low = 0 ; 
        int high = nums.size()-1;
        
        while(low <=high){
            int mid = low + (high-low)/2;

            // if(nums[low] <= nums[high]){
            //     mini = min(nums[low],mini);
            //     break;
            // }
            
            if(nums[low] <= nums[mid]){
                mini = min(nums[low],mini);
                low = mid+1;
            }
            else{
                mini = min(nums[mid],mini);
                high = mid-1;
            }
        }
        return mini ;
    }
};