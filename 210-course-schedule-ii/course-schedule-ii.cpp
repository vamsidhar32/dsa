class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans ;
        vector<int> adj[numCourses];
        vector<int>indegree(numCourses);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i =0 ; i<numCourses; i++ ){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            auto top=  q.front();
            q.pop();
            ans.push_back(top);
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        reverse(ans.begin(),ans.end());
        if(ans.size() == numCourses) return ans ;
        return {};

    }
};