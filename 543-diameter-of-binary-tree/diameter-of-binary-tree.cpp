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
    int height(TreeNode* root,int &diameter){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);

        int dia = lh+rh+1;

        if(diameter < dia){
            diameter = dia ;
        }

        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int heightt = height(root,diameter);

        return diameter-1 ;
    }
};