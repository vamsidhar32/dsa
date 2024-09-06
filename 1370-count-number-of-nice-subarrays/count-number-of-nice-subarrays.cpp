class Solution {
public:

    int atmost(vector<int>&nums,int k){
       // if(k == -1) return 0 ;
        int i = 0 ;
        int j = 0 ; 
        int n = nums.size();
        int odd = 0 ;
        int count = 0 ;
        while(j<n){
            if(nums[j] % 2 == 1) odd++;
            if(odd <=k){
                count = count + (j-i+1);
                j++;
            }
            else if(odd >k){
                while(odd >k){
                    if(nums[i] %2 == 1) odd--;
                    i++;
                }
                count = count + (j-i+1);
                j++;
            }
        }

        return count ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};