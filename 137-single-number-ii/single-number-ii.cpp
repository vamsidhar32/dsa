class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b1 = 0 ; int b2 = 0 ;
        for(int i = 0 ; i <nums.size() ; i++){
            b1 = b1^nums[i] & (~b2);

            b2 = b2^nums[i] & (~b1);
        }
        return b1 ;
    }
};