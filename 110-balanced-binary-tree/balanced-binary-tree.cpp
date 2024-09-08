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
    int height(TreeNode* root ,int &flag){
        if(flag == 1) return 1 ;
        if(root == NULL) return 0 ;

        int left = height(root->left,flag);
        int right = height(root->right,flag);
        if(abs(left - right) > 1) flag = 1 ;

        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int flag = 0 ;
        int hei = height(root,flag);
        if(flag == 1 )return false ;
        return true ;
    }
};