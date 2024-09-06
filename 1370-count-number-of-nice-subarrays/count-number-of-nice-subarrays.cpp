class Solution {
public:

    int func(vector<int> &nums,int k){
        if(k == -1) return 0 ;
        int i = 0 ;
        int j = 0 ;
        int odd  = 0 ;
        int count = 0 ;

        while( j < nums.size()){
            if(nums[j] % 2 == 1) odd++;
            
            if(odd <=k ){
                count += j-i+1;
                j++;
            }
            else if(odd > k){
                while(odd > k){
                    if(nums[i] %2 == 1) odd--;
                    i++;
                }
                count += j-i+1;
                j++;
            }
        }
        return count ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};