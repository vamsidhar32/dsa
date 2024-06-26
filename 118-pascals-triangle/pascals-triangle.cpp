class Solution {
public:
    vector<int> genrow(int num){
        vector<int> ans; 
        ans.push_back(1);
        int n = num-1;
        int value = 1 ;
        for(int i = 1  ; i < num ; i++){
            value = value*n; 
            n--;
            value = value/i ;
            ans.push_back(value);
        }

        return ans ;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1 ; i <= numRows ; i++){
            ans.push_back(genrow(i));
        }

        return ans ;
    }
};