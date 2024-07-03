class Solution {
public:
    typedef pair<string, int> pi;

    static bool comp(const pi &s1, const pi &s2) {
        if (s1.first.length() == s2.first.length()) {
            return s1.second < s2.second;
        }
        return s1.first.length() < s2.first.length();
    }

    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        text.push_back(' ');

        string temp = "";
        vector<pi> words;
        int number = 1;
        for (char ch : text) {
            if (ch == ' ') {
                words.push_back({temp, number++});
                temp = "";
            } else {
                temp += ch;
            }
        }

        sort(words.begin(), words.end(), comp);

        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += ' ';
            result += words[i].first;
        }

        result[0] = toupper(result[0]);
        return result;
    }
};
