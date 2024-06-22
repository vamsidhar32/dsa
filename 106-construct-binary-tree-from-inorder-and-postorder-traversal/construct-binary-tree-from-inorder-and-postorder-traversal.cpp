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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int is,int ie, int ps, int pe , unordered_map<int,int> &mp){
        if(is > ie || ps > pe){
            return NULL ;
        }
        TreeNode* root = new TreeNode(postorder[pe]);

        int num = mp[postorder[pe]];
        int count = num - is;

        root->left = build(inorder,postorder,is,num-1,ps,ps+count-1,mp) ;
        root->right = build(inorder,postorder,num+1,ie,ps+count,pe-1,mp) ;

        return root ;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int a = inorder.size();
        int b = postorder.size();

        if( a == 0 || b == 0 || a != b ){
            return NULL ;
        }
        unordered_map<int,int> mp;
        for(int i = 0 ; i<a ; i++){
            mp[inorder[i]] = i;
        }
        int is = 0 ;
        int ie = a-1 ;

        int ps = 0 ;
        int pe = b-1 ;
        TreeNode* root = build(inorder,postorder,is,ie,ps,pe,mp);

        return root ;
    }
};