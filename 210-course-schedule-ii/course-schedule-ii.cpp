class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> pre = prerequisites;

        vector<int>adj[n];
        vector<int>indegree(n);
        for(int i = 0 ; i <pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }

        

        // for(int i = 0 ; i <n ; i++){
        //     for(auto it :adj[i]){
        //         indegree[it]++;
        //     }
        // }
        queue<int>q;
        for(int i =0 ; i <n ; i++){
            if(indegree[i] == 0 ) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it :adj[top]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size() == n) return ans ;
        return {};
    }
};