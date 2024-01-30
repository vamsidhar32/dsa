/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root == NULL){
            return ans ;
        }

        queue<TreeNode*> q ;
        q.push(root);
        int flag = 1 ;

        while(!q.empty()){
            int k = q.size();
            int i = 0 ;
            vector<int>level(k);
            int j = k;
            while(j--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                if(flag == 1){
                    
                    level[i++] = temp->val ;
                }
                else if(flag == -1){
                    level[--k] = temp->val ;
                }

            }
            if(flag == 1){
                ans.push_back(level);
                flag = -1 ;
            }
            else if(flag == -1){
                //reverse(level.begin(),level.end());
                ans.push_back(level);
                flag = 1 ;
            } 

        }
        return ans ;
    }
};