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
    int maxsum(TreeNode* root , int &ans){
        if(root == NULL){
            return 0;
        }
        int left = maxsum(root->left,ans);
        if(left <0) left = 0;
        int right = maxsum(root->right,ans);
        if(right <0) right =0 ;

        ans = max(ans ,left+right+root->val);
        
        return max(left + root->val , right + root->val);

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int k = maxsum(root,ans);
        return ans ;
    }
};