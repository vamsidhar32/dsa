class Solution {
public:


int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    
    // Special case: if k equals n, return total sum.
    if (k == n) return totalSum;
    
    int windowSize = n - k;
    int currentWindowSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
    int minWindowSum = currentWindowSum;
    
    for (int i = windowSize; i < n; ++i) {
        currentWindowSum += cardPoints[i] - cardPoints[i - windowSize];
        minWindowSum = min(minWindowSum, currentWindowSum);
    }
    
    return totalSum - minWindowSum;
}

};