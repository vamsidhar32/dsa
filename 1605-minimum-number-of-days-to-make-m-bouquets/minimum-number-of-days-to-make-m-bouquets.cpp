class Solution {
public:
    int func(vector<int>& bloomDay, int mid ,int m , int k){
        int bouq = 0 ;
        int count = 0 ;
        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid) count++;
            else{
                bouq = bouq + count/k ;
                if(bouq ==m) return 1 ;
                count = 0 ;
            }
        }
        bouq = bouq+count/k;

        if(bouq >= m) return 1;
        return -1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long ad = (long long)(m) * (long long)(k) ;
        if(ad > n) return -1;
        int low = 1 ;
        int high = *(max_element(bloomDay.begin(),bloomDay.end()));

        while(low<=high){
            int mid = low + (high-low)/2;
            int comp = func(bloomDay,mid,m,k);
            if(comp == 1) high = mid-1;
            else low = mid+1 ;
        }

        return low ;
    }
};