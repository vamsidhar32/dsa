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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is, int ie,unordered_map<int,int> &mp){
        if(ps > pe || is > ie){
            return NULL ;
        }

        TreeNode* root = new TreeNode(preorder[ps]);

        int num = mp[preorder[ps]];
        int count = num - is ;


        root->left = build(preorder,inorder,ps+1, ps+count,is,num-1,mp);
        root->right = build(preorder,inorder,ps+count+1, pe,num+1,ie,mp);

        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int a = preorder.size();
        int b = inorder.size();
        unordered_map<int,int> mp ;
        for(int i = 0 ; i<b ; i++){
            mp[inorder[i]] = i ;
        }
        int ps = 0 ;
        int pe = a-1 ;
        int is = 0 ;
        int ie = a-1 ;
        TreeNode* root = build(preorder,inorder,ps,pe,is,ie,mp);

        return root ;
    }

};


















