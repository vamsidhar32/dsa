class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
       

        deque<int>dq;
        
        int i = 0 ; 
        int j = 0 ;
    
        while(j < nums.size()){
            if(dq.empty() || nums[j] <= dq.back()){
                dq.push_back(nums[j]);
            }
            else if(!dq.empty() && nums[j] > dq.back()){
                while(!dq.empty() && nums[j] > dq.back()){
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
            }
            

            if(j-i+1 <k) j++;
            else{
                // cout << j <<" " ;
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