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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return NULL ;
        }
        int pval = p->val ;
        int qval = q->val ;

        TreeNode* curr = root ;

        while(curr){
            if(curr->val > pval && curr->val > qval){
                curr = curr->left;
            }
            else if (curr->val < pval && curr->val < qval){
                curr = curr->right;
            }

            else return curr ;
        }

        return NULL ;
        
    }
};