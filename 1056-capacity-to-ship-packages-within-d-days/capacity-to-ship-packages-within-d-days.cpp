class Solution {
public:
    int func(vector<int> &weights , int mid , int days){
        int count = 0 ;
        int sum = 0 ;
        for(int i = 0 ; i <weights.size(); i++){
            sum = sum+weights[i] ;
            if(sum > mid){
                count++;
                sum = weights[i];
                if(count > days) return 0 ;
            }
        }
        count++;
        if(count <= days) return 1 ;
        return 0 ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *(max_element(weights.begin(),weights.end())) ; 
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            int comp = func(weights,mid,days);

            if(comp == 1) high = mid-1;
            else low = mid+1 ;
        }

        return low ;
    }
};