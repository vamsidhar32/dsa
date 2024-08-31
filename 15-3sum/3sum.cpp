class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans ;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i =0 ; i< nums.size(); i++){
            int sum = -nums[i];
            int j = i+1;
            int k = n-1;
            if(i != 0 && nums[i] == nums[i-1]) continue ;
            while(j < k){
                int value = nums[j] + nums[k];
                if(value < sum ) j++;
                else if(value > sum) k--;
                else if( value == sum){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans ;
    }
};