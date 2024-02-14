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
    int leftheight(TreeNode* root){
        int cnt = 0 ;
        while(root){
            root = root->left ;
            cnt++ ;
        }
        return cnt ;
    }
    
    int rightheight(TreeNode* root){
        int cnt = 0 ;
        while(root){
            root = root->right ;
            cnt++ ;
        }
        return cnt ;
    }

public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        //cout << (9 << 3) ;
        int left = leftheight(root->left);
        int right = rightheight(root->right);

        if(left == right) return (2 << left) - 1 ;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};