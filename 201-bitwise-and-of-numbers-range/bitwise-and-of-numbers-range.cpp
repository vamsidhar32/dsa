class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count =  0; 
        int k = left ;
        while(left != right){
            left = left >> 1;
            right = right >>1;
            count++;
        }

        return (left << count) ;
    }
};