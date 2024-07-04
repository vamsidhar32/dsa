class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        
        char ans = keysPressed[0];
        int diff = releaseTimes[0];

        for(int i = 1 ; i <releaseTimes.size();i++){
            int difference = releaseTimes[i]-releaseTimes[i-1];
            if(difference > diff){
                ans = keysPressed[i];
                diff = difference;
            }
            if(difference == diff){
                ans = max(ans,keysPressed[i]);
            }
        }

        return ans ;
    }
};