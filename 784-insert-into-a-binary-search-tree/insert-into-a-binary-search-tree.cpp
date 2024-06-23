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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root ;
        if(curr == NULL){
            return new TreeNode(val);
        }
        while(curr){
            if (curr->val == val) break;
            if(curr->val < val){
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                }
                curr = curr->right;
            }
            else if(curr->val > val){
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                }
                curr = curr->left ;
            }
        }

        return root ;
    }
};