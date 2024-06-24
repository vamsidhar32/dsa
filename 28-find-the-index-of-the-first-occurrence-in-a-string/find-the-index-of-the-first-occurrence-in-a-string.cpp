class Solution {
public:
    int strStr(string haystack, string needle) {
        int i  = 0 , j =0 ;
        int len = needle.length();
        int store = -1 ;
        int haylength = haystack.length();
        while(i<haylength){
            if(haystack[i] == needle[j]){
                while(j < len){
                    if(haystack[i+j] == needle[j]){
                        j++ ;
                    }
                    else {
                        j =0 ;
                        break ;
                    }

                }
                if(j == len){
                    store = i ;
                    break;
               }

            }
            i++ ;
        }
        if(store == -1){
            return -1 ;
        }

        else return (store ) ;
    }
};