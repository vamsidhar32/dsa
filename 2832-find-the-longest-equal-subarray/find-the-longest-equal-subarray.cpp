class Solution {
public:

    int update(unordered_map<int,int>mpp){
        int ans = 0 ;
        for(auto it : mpp){
            ans = max(ans,it.second);
        }
        return ans ;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        int  i =0 ;
        int j =0 ;

        unordered_map<int,int>mpp;
        int count = 0 ;
        int maxcount = 0 ;
        int ans = 1 ;
        while(j < nums.size()){
            mpp[nums[j]]++;
            count++;
            if(mpp[nums[j]] > maxcount){
                maxcount = mpp[nums[j]];
            }

            if(count-maxcount <= k){
                ans = max(maxcount,ans);
                j++;
            }
            else if(count - maxcount >k){
                if(count - maxcount > k){
                    mpp[nums[i]]--;
                    count--;
                    //maxcount = update(mpp);
                    i++; 
                }
                j++;
            }
        }

        return ans ;
    }
};