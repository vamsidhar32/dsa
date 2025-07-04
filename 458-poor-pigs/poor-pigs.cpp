#include <iostream>
#include <cmath>  // For using pow() function
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Calculate how many complete test rounds we can perform
        int tests = minutesToTest / minutesToDie;

        // Initialize pig count to 0
        int pigs = 0;

        // We increase the number of pigs until we can cover all bucket combinations
        // Each pig can encode (tests + 1) states
        while (pow(tests + 1, pigs) < buckets) {
            pigs++;  // Add another pig and try again
        }

        // Return the minimum pigs needed to uniquely determine the poisonous bucket
        return pigs;
    }
};
