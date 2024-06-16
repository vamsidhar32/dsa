class Solution {
public:
    int beautySum(string s) {
        int ans = 0 ;
        if(s.size() == 0) return 0;
        for(int i = 0 ; i <s.size()  ; i++){
            unordered_map<char,int>mpp;
            for(int j =  i ; j <s.size(); j++){
                mpp[s[j]]++;
                int maxx = INT_MIN;
                int minn = INT_MAX;

                for(auto it :mpp){
                    maxx =max(maxx,it.second);
                    minn =min(minn,it.second);
                }

                ans = ans+maxx-minn;
            }
            mpp.clear();
        }

        return ans ;
    }
};