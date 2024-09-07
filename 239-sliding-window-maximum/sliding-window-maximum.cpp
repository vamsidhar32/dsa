class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0 ;
        int j =0 ;
        deque<int>dq ;
        vector<int>ans ;
        while(j < nums.size()){        
            while(!dq.empty() && nums[j] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);            

            if(j-i+1 <k) j++;
            else{
                ans.push_back(dq.front());
                if(nums[i] == dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans ;
    }
};