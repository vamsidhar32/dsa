
class Solution {
public:
    bool isNumber(string s) {
        bool numSeen = false;     // Tracks if a digit has been seen
        bool dotSeen = false;     // Tracks if a dot '.' has been seen
        bool eSeen = false;       // Tracks if an 'e' or 'E' has been seen
        bool numAfterE = true;    // Tracks if there's a digit after 'e'
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                numSeen = true;
                if (eSeen) numAfterE = true;
            }
            else if (s[i] == '.') {
                // Only one dot allowed and no dot after e
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                // Only one e allowed and must have a number before
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numAfterE = false;  // Must reset and require a digit after e
            }
            else if (s[i] == '+' || s[i] == '-') {
                // Sign is only valid at start or just after e
                if (i != 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
            }
            else {
                // Invalid character
                return false;
            }
        }
        return numSeen && numAfterE;
    }
};
