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
    void preorder(TreeNode* root , vector<int> &ans,int level){
        if(root == NULL){
            return ;
        }
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        level++ ;
        preorder(root->right,ans,level);
        preorder(root->left,ans,level);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0 ;
        preorder(root,ans,level);
        return ans ;
        
    }
};