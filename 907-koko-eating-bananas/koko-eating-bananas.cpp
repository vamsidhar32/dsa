class Solution {
public:
    int func(vector<int>piles,int mid , int h){
        long long hours = 0 ;

        for(int i = 0 ; i < piles.size(); i++){
            hours = hours + piles[i]/mid ;
            if(piles[i]%mid != 0) hours++;
        }
        if(hours <= h) return 1 ;
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n) return -1;

        int low = 1 ;
        int high = *(max_element(piles.begin(),piles.end())) ;

        while(low <=high){
            int mid = low + (high-low)/2;
            int comp = func(piles,mid,h);
            if(comp == 1) high = mid-1;
            else low = mid+1 ;
        }

        return low ;
    }
};