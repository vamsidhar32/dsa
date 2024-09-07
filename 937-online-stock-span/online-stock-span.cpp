class StockSpanner {
public:
    int index = -1 ;
    stack<pair<int,int>>st;

    StockSpanner() {
        index = -1 ;
    }
    
    int next(int price) {
        index = index+1 ;
        if(st.empty()){
            int ans = 1 ;
            st.push({price,index});
            return ans ;
        }
        else{
            int ans ;
            while(!st.empty() && price >= st.top().first){
                st.pop();
            }
            if(st.empty()) ans = index+1;
            else ans = index - st.top().second;
            st.push({price,index});

            return ans ;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */