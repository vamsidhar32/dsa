class Solution {
    bool canForm(string& word, unordered_set<string>& dict) {
        if (dict.empty()) return false;
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });

        unordered_set<string> dict;
        vector<string> result;

        for (string& word : words) {
            if (canForm(word, dict)) {
                result.push_back(word);
            }
            dict.insert(word);
        }

        return result;
    }
};
