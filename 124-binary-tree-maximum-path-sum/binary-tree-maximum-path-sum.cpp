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

    int sum(TreeNode* root,int &maxpathsum){
        if(root == NULL) return 0 ;
        int left = sum(root->left,maxpathsum);
        if(left <0) left = 0 ;
        int right = sum(root->right,maxpathsum);
        if(right<0) right = 0 ;
        maxpathsum = max(maxpathsum,left+right+root->val);
        return root->val + max(left,right) ;

    }
    int maxPathSum(TreeNode* root) {
        if(root == 0) return 0 ;
        int maxpathsum = INT_MIN;
        int su = sum(root,maxpathsum);

        return maxpathsum;
    }
};