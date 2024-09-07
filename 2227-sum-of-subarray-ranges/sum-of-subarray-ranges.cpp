class Solution {
public:
    void func1(vector<int> &nums, vector<int>&nsl){
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i = 0 ; i < nums.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push({nums[i],i});
            }
            else if(nums[i] > st.top().first){
                ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && nums[i] <= st.top().first){
                    st.pop();
                }
                if(st.empty())ans.push_back(-1);
                else ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
        }
        nsl = ans ;
    }

    void func2(vector<int> &nums, vector<int>&nsr){
        stack<pair<int,int>>st;
        vector<int>ans;
        int n = nums.size();
        for(int i = n-1 ; i >=0 ; i--){
            if(st.empty()){
                ans.push_back(n);
                st.push({nums[i],i});
            }
            else if(nums[i] >= st.top().first){
                ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && nums[i] < st.top().first){
                    st.pop();
                }
                if(st.empty())ans.push_back(n);
                else ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
        }
        reverse(ans.begin(),ans.end());
        nsr =  ans ;
    }

    void func3(vector<int> &nums, vector<int>&ngl){
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i = 0 ; i < nums.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push({nums[i],i});
            }
            else if(nums[i] < st.top().first){
                ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && nums[i] >= st.top().first){
                    st.pop();
                }
                if(st.empty())ans.push_back(-1);
                else ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
        }
        ngl = ans ;
    }

    void func4(vector<int> &nums, vector<int>&ngr){
        stack<pair<int,int>>st;
        vector<int>ans;
        int n = nums.size();
        for(int i = n-1 ; i >=0; i--){
            if(st.empty()){
                ans.push_back(n);
                st.push({nums[i],i});
            }
            else if(nums[i] <= st.top().first){
                ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && nums[i] > st.top().first){
                    st.pop();
                }
                if(st.empty())ans.push_back(n);
                else ans.push_back(st.top().second);
                st.push({nums[i],i});
            }
        }
        reverse(ans.begin(),ans.end());
        ngr = ans ;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0 ;
        vector<int>nsl;
        vector<int>nsr;
        vector<int>ngr;
        vector<int>ngl;
        func1(nums,nsl);
        func2(nums,nsr);
        func3(nums,ngl);
        func4(nums,ngr);

        long long int summin = 0 ;
        long long int summax = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            int l = i - nsl[i];
            int r = nsr[i] - i ;
            summin += (long long)(nums[i])*(long long)(l)*(long long)(r) ;

            int l2 = i-ngl[i];
            int r2 = ngr[i]-i;
            summax += (long long)(nums[i])*(long long)(l2)*(long long)(r2) ;

        }

        return summax- summin;
    }
};