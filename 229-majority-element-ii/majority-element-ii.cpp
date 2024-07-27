class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans ;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN; 
        int count1 = 0 ;
        int count2 = 0 ;

        for(int i = 0 ; i < nums.size() ; i++){
            
            if(count1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                count1 = 1 ;
            } 
            else if(count2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                count2 = 1 ;
            }
            else if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;

            else{
                count1--;
                count2--;
            }
        }

        int c = 0 , c2 = 0; 

        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] == ele1) c++;
            if(nums[i] == ele2) c2++;
        }
        int n = nums.size();
        if(c>=(n/3)+1) ans.push_back(ele1);
        if(c2>= (n/3)+1) ans.push_back(ele2);


        return ans ;
    }
};