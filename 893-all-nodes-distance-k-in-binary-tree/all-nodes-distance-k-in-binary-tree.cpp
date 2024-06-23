/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solveparents(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode*root){

        if(root == NULL) return ;
        queue<TreeNode*>q;
        q.push(root);
        parent[root] = NULL ;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i <size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }

            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans ;
        if(root == NULL) return ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        solveparents(parent,root);

       
        unordered_map<TreeNode*,bool>visited;

        queue<TreeNode*>q;
        q.push(target);

        visited[target] = true;
        int level = 0 ;

        while(!q.empty()){
            int size = q.size();
            level++;

            if(level == k+1) break;

            for(int i = 0 ; i <size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true ;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true ;
                }
            }
            
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans ;

    }
};