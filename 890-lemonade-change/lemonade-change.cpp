class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        map<int,int> mp;
        mp[5] = 0;
        mp[10] = 0;
        mp[20] = 0 ;

        for(int i = 0 ;i <bills.size();i++){
            if(bills[i] == 5){
                mp[5]++ ;
            }
            if(bills[i] == 10){
                if(mp[5] < 1){
                    return false ;
                }
                mp[10]++;
                mp[5]-- ;
            }
            if(bills[i] == 20){
                if(mp[10] >= 1 && mp[5] >= 1){
                    mp[5]-- ;
                    mp[10] -- ;
                }

                else if(mp[10] < 1 && mp[5] >= 3){
                    mp[5] = mp[5] - 3 ;
                    mp[20]++ ;
                }
                else return false;

            }
        }
        return true;





    }
       
};