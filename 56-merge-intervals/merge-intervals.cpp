class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans ;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        int a = intervals[0][0];
        int b = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] <= b){
                b = max(b,intervals[i][1]);
            }
            else if(intervals[i][0] > b){
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a,b});

        return ans;
    }
};