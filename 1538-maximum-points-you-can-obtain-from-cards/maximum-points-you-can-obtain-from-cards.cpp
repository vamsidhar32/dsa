class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0 ;
        int i = n-k;
        int j = n-k;
        int sum =0 ; 

        while(j<n+k){
            sum = sum+ cardPoints[j%n]; 
            if(j-i+1 < k){
                j++;
            }
            else{
                ans = max(ans,sum);
                sum = sum - cardPoints[i%n];
                j++;
                i++;
            }
        }
        return ans ;
    }
};