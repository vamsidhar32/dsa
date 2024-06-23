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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int flag = 1 ;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0 ; i <s ; i++){
                pair<TreeNode*,int>p = q.front();
                q.pop();
                if(flag == 1){ans.push_back(p.first->val);flag = 0 ;}
                if(p.first->right) q.push({p.first->right,p.second+1});
                if(p.first->left) q.push({p.first->left,p.second+1});  
            }
            flag = 1 ;
        }

        return ans ;
    }
};