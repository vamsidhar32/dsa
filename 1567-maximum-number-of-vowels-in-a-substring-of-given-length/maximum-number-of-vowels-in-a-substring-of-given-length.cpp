class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();

        int i = 0 ; 
        int j = 0 ;
        int vowels = 0;
        int ans = 0 ;
        while(j < n){
            if(s[j] == 'a' ||s[j] == 'u' || s[j] == 'o' || s[j] == 'i'||s[j] == 'e'){
                vowels++;
            }

            if(j-i+1 < k){
                j++;
                continue ;
            } 

            else {
                ans =max(ans,vowels);
                if(s[i] == 'a' ||s[i] == 'u' || s[i] == 'o' || s[i] == 'i'||s[i] == 'e'){
                    vowels--;
                }
                j++;
                i++;
            }

        }

        return ans ;
    }
};