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
    int height(TreeNode* root , int &pathsum){
        if(root == NULL) return NULL ;

        int left = height(root->left,pathsum);
        int right = height(root->right,pathsum);

        if(left < 0) left = 0 ;
        if(right <0) right = 0;

        pathsum = max(pathsum,root->val+left+right);

        return (root->val + max(left,right));

    }
    int maxPathSum(TreeNode* root) {
        int pathsum  = INT_MIN ;

        int hei = height(root,pathsum);

        return pathsum ;
        
    }
};