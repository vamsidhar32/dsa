class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = 1 ;
        int k ;
        for(int i = n-2 ; i >=0 ; i--){
            if(nums[i] < nums[i+1]){
                flag = 0 ;
                k = i ;
                break;
            }
        }
        if(flag == 1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] > nums[k]){
                swap(nums[k],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());
    }
};