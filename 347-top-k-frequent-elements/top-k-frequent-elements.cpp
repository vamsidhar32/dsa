class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0 ; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            pq.push({it.second,it.first});

            if(pq.size() > k){
                pq.pop();
            }

        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        


    }
};