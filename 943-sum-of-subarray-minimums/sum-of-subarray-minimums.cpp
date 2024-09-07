class Solution {
public:
    #define mod 1000000007
    void func1(vector<int>arr , vector<int> &nsil){

        stack<pair<int,int>>st;
        for(int i =0 ; i < arr.size() ; i++){
            if(st.empty()){
                nsil.push_back(-1);
                st.push({arr[i],i});
            }
            else if(arr[i] >= st.top().first){
                nsil.push_back(st.top().second);
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && arr[i] < st.top().first ){
                    st.pop();
                }
                if(st.empty()) nsil.push_back(-1);
                else nsil.push_back(st.top().second);
                st.push({arr[i],i});
            }
        }
    }
    void func2(vector<int>arr, vector<int>&nsir){
        stack<pair<int,int>>st;

        for(int i = arr.size()-1; i >=0 ; i--){
            if(st.empty()){
                nsir.push_back(arr.size());
                st.push({arr[i],i});
            }
            else if(arr[i] > st.top().first){
                nsir.push_back(st.top().second);
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && arr[i] <= st.top().first){
                    st.pop();
                }
                if(st.empty()) nsir.push_back(arr.size());
                else nsir.push_back(st.top().second);
                st.push({arr[i],i});
            }
        }
        reverse(nsir.begin(),nsir.end());
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsil;
        vector<int> nsir;
        func1(arr,nsil);
        func2(arr,nsir);
        int sum =0 ;
        for(int i = 0 ; i< arr.size(); i++){
            int l = i - nsil[i];
            int r = nsir[i] - i ;
            sum = (long long)(sum % mod) + (long long)((arr[i] %mod ) * (long long)((l%mod) *  (long long)(r %mod))%mod )% mod;
        }
        return sum ;
    }
};