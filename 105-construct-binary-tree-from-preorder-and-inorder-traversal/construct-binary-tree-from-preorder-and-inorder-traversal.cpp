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


    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int ps, int pe , int is , int ie, unordered_map<int,int>&inmap){

        if(pe < ps || ie < is) return NULL ;
        TreeNode* root = new TreeNode(preorder[ps]);

        int iend = inmap[preorder[ps]];
        int diff = iend - is ;

        root->left = build(preorder,inorder,ps+1,ps+diff,is,iend-1,inmap);
        root->right = build(preorder,inorder,ps+diff+1,pe,iend+1,ie,inmap);

        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int>inmap;
        for(int i =0 ; i < n ; i++){
            inmap[inorder[i]] = i ;
        }

        int ps = 0 ; 
        int pe = n-1 ;
        int is = 0 ;
        int ie = n-1;


        return build(preorder,inorder,ps,pe,is,ie,inmap);
    }
};