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
    bool issyym(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL || root2 == NULL) return root1 == root2;

        if(root1->val != root2->val) return false ;
        bool left = issyym(root1->left,root2->right);
        if(left == false )return false ;
        bool right = issyym(root1->right,root2->left);
        if(right == false ) return false ;

        return true ;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        if(root->left == NULL || root->right == NULL) return root->left == root->right ;
        
        bool k = issyym(root->left,root->right);
        return k;
    }
};