class Solution {
public:

    int func(vector<int>& nums, int mid , int k){

        int subarrays = 0;
        int sum = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            sum = sum+nums[i];
            if(sum>mid){
                subarrays++;
                sum = nums[i];
            }
        }
        subarrays++;

        if(subarrays <= k) return 1 ;
        return 0;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());

        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            int comp = func(nums,mid,k);
            cout << mid << " " << comp << " " << endl;
            if(comp == 1){
                high = mid-1;
            }
            else low = mid+1;

        }

        return low ;
    }
};