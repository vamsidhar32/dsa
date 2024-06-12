class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st ;
        int n = nums.size();
        if(n == 0 ){
            return 0;
        }

        for(int i = 0 ; i< n ; i++){
            st.insert(nums[i]);
        }
        
        int ans = 1 ;
        int count = 1 ;
        int prev = *(st.begin());
        auto it = st.begin();
        it++;
        for(it ; it != st.end(); it++){
            if(*(it)-1 == prev){
                count++;
                prev = *(it);
            }
            else{
                count = 1;
                prev = *(it);
            }

            ans = max(ans ,count);
        }

        return ans ;


    }
};