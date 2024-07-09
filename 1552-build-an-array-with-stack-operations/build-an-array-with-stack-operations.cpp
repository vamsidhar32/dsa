class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int k = target.size();
        int i = 0 ; 
        int j = 1 ;

        while(i<k && j <=n ){
            if(target[i] == j){
                ans.push_back("Push");
                i++;
                j++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            }
        }

        return ans ;
    }
};