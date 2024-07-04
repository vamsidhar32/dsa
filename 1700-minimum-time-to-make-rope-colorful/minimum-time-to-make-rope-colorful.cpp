class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                if (neededTime[i] < neededTime[i - 1]) {
                    ans += neededTime[i];
                    neededTime[i] = neededTime[i - 1];
                } else {
                    ans += neededTime[i - 1];
                }
            }
        }

        return ans;
    }
};
