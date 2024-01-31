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
private:
    bool preorder(TreeNode* leftt , TreeNode* rightt){
        if(leftt == NULL || rightt == NULL){
            return leftt == rightt ;
        }
        if(leftt->val != rightt->val) return false ;
        bool a = preorder(leftt->left ,rightt->right);
        bool b = preorder(leftt->right, rightt->left);
        return a && b ;
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true ;
        bool ans = preorder(root->left, root->right);
        return ans ;
    }
};