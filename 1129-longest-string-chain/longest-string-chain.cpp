class Solution {
public:

    static bool comp(string &s1 , string &s2){
        return s1.length() < s2.length();
    }


    bool compare(string s1 , string s2){
        if(s1.size()  != s2.size() + 1 ) return false ;
        int j =0 ;
        int i = 0 ;
        int flag = 0 ;

        while(1){
            if(i == s1.size()) return true ;
            if(s1[i] != s2[j]){
                if(flag ==1 ) return false ;
                flag = 1;
                i++;
                continue;
            }
            i++;
            j++;
        }
        
        
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);

        int ans = -1;
        vector<int>dp(n,1);
        vector<int>hash(n,-1);
        int index = -1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(compare(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] +1 ;
                    hash[i] = j ;
                }
            }

            if(dp[i] > ans ){
                ans = dp[i] ;
                index = i ;
            }
        }

        vector<string>temp ;
        while(hash[index] != -1){
            temp.push_back(words[index]);
            index = hash[index];
        }
        temp.push_back(words[index]);

        for(int i = 0 ; i < temp.size(); i++){
            cout << temp[i] << " " ;
        }
        return ans ;
    }
};