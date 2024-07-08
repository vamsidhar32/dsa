class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        queue<int> r; 
        queue<int>d;

        for(int i = 0 ; i <senate.size();i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        while(!r.empty() && !d.empty()){
            int i = r.front();
            int j = d.front();
            if(i < j){
                d.pop();
                r.push(i+n);
                r.pop();
            }
            else{
                r.pop();
                d.push(j+n);
                d.pop();
            }
        }

        if(r.size())return "Radiant";
        return "Dire";
    }
};