class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string> st;
        vector<int>dp(n+1,-1);
        return dfs(s, 0, st,dp);
    }
    
    int dfs(const string& s, int start, unordered_set<string>& st,vector<int>&dp) {
        if (start == s.size()) {
            return 0;
        }
        
        int maxCount = 0;
        string temp = "";
        
        for (int i = start; i < s.size(); ++i) {
            temp += s[i];
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                maxCount = max(maxCount, 1 + dfs(s, i + 1, st,dp));
                st.erase(temp);
            }
        }
        
        return maxCount;
    }
};
