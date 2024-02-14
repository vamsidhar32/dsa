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
    private:
    void bfsparent(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parents[node->left] = node ;
                }
                if(node->right){
                    q.push(node->right);
                    parents[node->right] = node ;
                }
            }
        }
    }    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans ;
        unordered_map<TreeNode*,TreeNode*>parents;
        
        unordered_set<TreeNode*> s ;

        bfsparent(root,parents);
        queue<TreeNode*>q ;

        q.push(target);
        s.insert(target);
        
        while(k--){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && s.find(node->left) == s.end()){
                    q.push(node->left);
                    s.insert(node->left);
                }
                if(node->right && s.find(node->right) == s.end()){
                    q.push(node->right);
                    s.insert(node->right);
                } 
                if(parents[node] && s.find(parents[node]) == s.end() ){
                    q.push(parents[node]);
                    s.insert(parents[node]);
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