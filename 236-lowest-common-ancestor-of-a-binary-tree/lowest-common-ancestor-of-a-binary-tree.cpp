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
    TreeNode* lowest(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(root == NULL) return NULL;

        if(root == p || root == q) return root ;

        TreeNode* left = lowest(root->left,p,q,ans);
        TreeNode* right = lowest(root->right,p,q,ans);

        if(left && right) {
            ans = root ;
            return root ;
        }
        if(left) return left ;
        if(right) return right;
        return NULL;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) return NULL ;
        TreeNode* ans =  NULL ;
        TreeNode* temp = lowest(root,p,q,ans);

        if(ans == NULL) return temp ;
        else return ans;
    }
};