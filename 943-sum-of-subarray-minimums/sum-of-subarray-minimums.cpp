class Solution {
public:
    #define mod 1000000007
    void func1(vector<int> &ans, vector<int>&arr){
        stack<pair<int,int>>st;

        for(int i = arr.size()-1; i>=0; i--){
            if(st.empty()){
                ans.push_back(arr.size());
                st.push({arr[i],i});
            }
            else if(arr[i] >= st.top().first){
                ans.push_back(st.top().second);
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && arr[i] < st.top().first){
                    st.pop();
                }
                if(st.empty()) ans.push_back(arr.size());
                else ans.push_back(st.top().second);
                st.push({arr[i],i});
            }

        }
        reverse(ans.begin(),ans.end());

    }




    void func2(vector<int> &ans, vector<int>&arr){
        stack<pair<int,int>>st;

        for(int i = 0; i <arr.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push({arr[i],i});
            }
            else if(arr[i] > st.top().first){
                ans.push_back(st.top().second);
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && arr[i] <= st.top().first){
                    st.pop();
                }
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top().second);
                st.push({arr[i],i});
            }

        }
    }


    int sumSubarrayMins(vector<int>& arr) {
        vector<int>ngli;
        vector<int>ngri;

        func1(ngri,arr);
        func2(ngli,arr);
        // for(int i = 0 ; i <arr.size(); i++){
        //     cout << ngri[i] << " "  <<endl;
        // }
        // for(int i = 0 ; i <arr.size(); i++){
        //     cout << ngli[i] << " "  <<endl;
        // }

        long long sum = 0 ;
        for(int i = 0 ; i <arr.size(); i++){

            int l = (i- ngli[i] )% mod;
            int r = (ngri[i] - i) % mod ;

            //cout << l << " " << r << " " ;
            sum = (long)(sum) % mod + (long)(arr[i]) % mod * (long)(l) % mod * (long)(r) % mod ; 
            //cout<<sum << " " << endl ;

            //answer += (long) (l) * (r) % mod * arr[i] % mod;
            sum %= mod;

        }
        return sum ;

    }
    
};