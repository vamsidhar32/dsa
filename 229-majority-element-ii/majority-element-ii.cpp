class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans ;
        int n = nums.size();
        int count1 = 0 ; 
        int count2 = 0 ; 
        int ele1 = INT_MIN ; int ele2 = INT_MIN ;
        for(int i =0 ; i <nums.size() ; i++){

            if(count1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                count1 = 1 ;
            }

            else if(count2 == 0 && nums[i] != ele1){
                ele2 = nums[i] ;
                count2 = 1;
            }
            else if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
            else {
                count1--;
                count2--;
            }
        }

        int cnt1 = 0 ;
        int cnt2 = 0 ;
        for(int i = 0 ; i <n ; i++){
            if(nums[i] == ele1) {
                cnt1++;
            }
            if(nums[i] == ele2){
                cnt2++;
            }
        }

        if(cnt1 >= int(n/3)+1) ans.push_back(ele1);
        if(cnt2 >= int(n/3)+1) ans.push_back(ele2);

        return ans;
    }
};