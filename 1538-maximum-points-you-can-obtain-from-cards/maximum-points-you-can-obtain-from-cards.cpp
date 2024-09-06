class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int i = n-k;
        int j = n-k;
        int ans = 0 ;
        int sum = 0 ;
        while( j < n+k ){
            sum += cardPoints[j%n];
            if(j < n){
                ans = max(ans,sum);
                j++;
            }
            else{
                sum -= cardPoints[i%n];
                i++;
                ans = max(ans ,sum);
                j++;
            }
        }

        return ans ;
    }
};