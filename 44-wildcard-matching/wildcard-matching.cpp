

class Solution {
public:
    // ------------------------------------------------------------
    // Returns true if pattern p matches the entire string s
    // ------------------------------------------------------------
    bool isMatch(string s, string p) {

        size_t sIdx = 0;          // current index in s
        size_t pIdx = 0;          // current index in p
        size_t starIdx = string::npos; // position of last '*' in p, npos = not seen
        size_t matchIdx = 0;      // position in s that corresponds to char right AFTER last '*'

        // Walk through the string
        while (sIdx < s.size()) {

            // Case-1: current chars match, or pattern has '?'
            if (pIdx < p.size() &&
               (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
                ++sIdx;           // consume one char from s
                ++pIdx;           // ... and one from p
            }

            // Case-2: pattern char is '*'
            else if (pIdx < p.size() && p[pIdx] == '*') {
                starIdx = pIdx;   // remember where the '*'
                matchIdx = sIdx;  // remember where in s the star may start matching
                ++pIdx;           // treat '*' as matching zero chars for now
            }

            // Case-3: mismatch BUT we have a previous '*' to fall back on
            else if (starIdx != string::npos) {
                pIdx = starIdx + 1; // reset pattern to char after '*'
                ++matchIdx;         // let '*' absorb one more char
                sIdx = matchIdx;    // retry matching from new sIdx
            }

            // Case-4: mismatch and NO previous '*' → impossible
            else {
                return false;     // no way to match
            }
        }

        // We finished the string; any remaining pattern chars must all be '*'
        while (pIdx < p.size() && p[pIdx] == '*') {
            ++pIdx;               // skip redundant '*' at the end
        }

        return pIdx == p.size();  // true only if pattern fully consumed
    }
};
