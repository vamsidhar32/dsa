class Solution {
public:


    vector<int> genrow(int row){
        vector<int> ans ;
        ans.push_back(1);
        int nume = row-1;
        int value = 1 ;
        for(int i = 1 ; i < row ; i++){
            value = value * nume ;
            value = value /i;
            nume--;
            ans.push_back(value);
        }

        return ans ;
    }


    int ncr(int n , int r){
        int value = 1 ;
        int nume = n-1;
        for(int i = 1 ; i < r ; i++){
            value = value*nume ;
            value = value/i;
            nume--;
        }

        return value ;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i = 1 ; i <= numRows ; i++){
            ans.push_back(genrow(i));
        }
        cout << ncr(6,3) << " " << ncr(7,4) << " " << ncr(7,3) ;
        return ans ;

    }
};