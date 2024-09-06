class Solution {
public:
    string minWindow(string s, string t) {
        
        int i =0 ;
        int j =0 ;

        int len = 1e9 ;
        unordered_map<int,int>mpp;
        for(int i = 0; i < t.size() ; i++){
            mpp[t[i]]++;
        }
        int count = mpp.size();

        int left= 0 ;
        int right = 0 ;

        while(j < s.size()){
            if(mpp.find(s[j]) != mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) count-- ;
            }

            if(count > 0){
                j++;
            }

            else if(count == 0){
                while(count == 0){
                    if( j-i+1 < len){
                        left = i ;
                        right = j ;
                        len = j-i+1;
                    }

                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]] == 1) count++;
                    }
                    i++;
                }
                j++;
                
            }
        }

        if(len == 1e9) return "";
        return s.substr(left,right-left+1);
    }

};