class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = n-k;
        int j = n-k;
        int sum = 0 ;
        int ans = 0 ;
        while( j < n+k){
            sum = sum+ cardPoints[j%n];
            if(j < n-1){
                j++;
            }
            else{
                ans = max(ans,sum);
                sum = sum - cardPoints[i%n];
                i++;
                j++;
            }
        }

        return ans ;
    }
};