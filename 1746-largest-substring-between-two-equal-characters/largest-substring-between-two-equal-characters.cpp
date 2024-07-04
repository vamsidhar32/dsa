class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        vector<int>hash(26,-1);
        int ans = -1;

        for(int i = 0 ; i <s.size();i++){
            if(hash[s[i] - 'a'] == -1){
                hash[s[i]-'a'] = i ;
            }

            else{
                ans = max(ans,i - hash[s[i]-'a'] -1 );
            }
        }

        return ans ;
        
    }
};