class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans ;
        int count = days ;

        if(meetings.size() == 0){
            return days ;
        }
        sort(meetings.begin(),meetings.end());

        count = count - (meetings[0][1]-meetings[0][0]+1);
        int prevday = meetings[0][1];
        for(int i = 1 ; i <meetings.size(); i++){

            if(meetings[i][1] <= prevday) continue ;
            else if(meetings[i][0] <= prevday){
                count -= meetings[i][1] - prevday;
                prevday = meetings[i][1];
            }
            else{
                count -= meetings[i][1] - meetings[i][0] +1;
                prevday = meetings[i][1];
            }

            cout << count << " " ;
        }

        return count ;
    }
};