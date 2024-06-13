class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans ;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n ; i++){

            if(i !=0 && nums[i-1] == nums[i]) continue;
            int j = i+1;
            int k = n-1;

            if(nums[i] > 0) break;
            int sum = -(nums[i]);
            

            while(j<k){
                int value = nums[j] + nums[k];
                if(value < sum){
                    j++;
                }
                else if(value == sum){
                    vector<int> temp ;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++; k--;
                    while(j<k && nums[j-1] == nums[j]) j++;
                    while(j<k && nums[k] == nums[k+1]) k-- ;
                }

                else if(value > sum){
                    k--;
                    
                }
            }    
        }
        return ans ;
    }
};