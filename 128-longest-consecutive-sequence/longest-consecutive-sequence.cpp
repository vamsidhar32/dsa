class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;

        for(int i =0 ; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int length = 0 ;
        for(auto it :st){
            if(st.find(it-1) != st.end()) continue;
            int count = 1 ;
            int ele = it;
            while(1){
                if(st.find(ele+1) != st.end()){
                    count++;
                    ele++;
                }
                else {
                    length = max(length,count);
                    break;
                }
            }
        }

        return length;
    }
};