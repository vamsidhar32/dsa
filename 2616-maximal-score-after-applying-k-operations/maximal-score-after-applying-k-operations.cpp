class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0 ;

        priority_queue<int>pq;
        for(int i =0 ; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k--){
            int x = pq.top();
            pq.pop();
            sum += x ;
            int ceil = x/3;
            if(x%3) ceil += 1 ;
            pq.push(ceil);
        }

        return sum ;
    }
};