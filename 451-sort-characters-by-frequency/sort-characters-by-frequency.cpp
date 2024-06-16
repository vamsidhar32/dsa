class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        
        priority_queue<pair<int,char>> pq;
        for(int i = 0 ; i < s.size() ; i++){
            mpp[s[i]]++;
        }
        for(auto it :mpp){
            pq.push({it.second,it.first});
        }


        string ans ="" ;

        while(!pq.empty()){
            pair<int,char> p = pq.top();

            int n = p.first ;
            char ch = p.second;
            for(int i = 0 ; i <n ; i++)  ans += ch;
            pq.pop();
        }

       

        return ans;
        

    }
};