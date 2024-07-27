class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for nums[i]
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int sum = -nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int value = nums[j] + nums[k];
                if (value < sum) j++;
                else if (value > sum) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Skip duplicates for nums[j]
                    while (j < k && nums[j] == nums[j-1]) j++;
                    // Skip duplicates for nums[k]
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};
