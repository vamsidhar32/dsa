class Solution {
public:
    int func(vector<int> &nums ,int mid ,int threshold){
        long long ans = 0;
        for(int i =0 ; i <nums.size(); i++){
            ans = ans + nums[i]/mid ;
            if(nums[i] % mid != 0) ans++ ;
            if(ans > threshold) return 0;
        }

        if(ans <= threshold) return 1 ;
        return 0 ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(threshold < n) return -1;

        int low = 1 ; 
        int high = *(max_element(nums.begin(),nums.end()));

        while(low <= high){
            int mid = low + (high -low) /2;
            int comp = func(nums,mid,threshold);

            if(comp == 1) high = mid-1 ;
            else low = mid+1;
        }

        return low ;
    }
};