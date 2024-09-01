class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int a = intervals[0][0];
        int b = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] <=b){
                b = max(b,intervals[i][1]);
                continue;
            }
            else if( intervals[i][0] >b){
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a,b});
        return ans ;
    }
};