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
    TreeNode* helper(TreeNode* root ){
        // if(root->left == NULL && root->right == NULL){
        //     delete root ;
        //     return NULL ;
        // } 
        if(root->left == NULL) {
            TreeNode* temp = root->right ;
            delete root ;
            return temp ;
        }
        if(root->right == NULL) {
            TreeNode* temp = root->left;
            delete root ;
            return temp ;
        }
        TreeNode* cut =root->right ;
        TreeNode* curr = root->left ;

        while(curr->right){
            curr = curr->right ;
        }
        curr->right = cut ;

        TreeNode* temp = root->left ;
        delete root ;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* curr = root ;
        if(curr == NULL) return NULL;
        if(curr->val == key){
            return helper(curr);
        }
        while(curr){
            if(curr->val <key){
                if(curr->right && curr->right->val == key){
                    curr->right = helper(curr->right);
                }
                curr = curr->right ;
            }
            else if (curr->val >key){
                if(curr->left && curr->left->val == key){
                    curr->left = helper(curr->left);
                }
                curr = curr->left ;
            }
        }
        return root ;
    }
};