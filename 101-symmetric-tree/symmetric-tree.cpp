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
    bool issym(TreeNode* node1,TreeNode* node2){
        if(node1 == NULL || node2 == NULL) return node1 == node2;

        if(node1->val != node2->val) return false ;
        bool left= issym(node1->left,node2->right);
        if(left == false) return false ;
        bool right = issym(node1->right, node2->left);
        if(right == false) return false;

        return left && right ;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true ;
        return issym(root->left ,root->right);
    }
};