/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildtree(vector<int>& inorder, vector<int>& postorder, int ps, int pe, int is, int ie, unordered_map<int, int>& inmap) {
        if (ps > pe || is > ie) return NULL;
        TreeNode* node = new TreeNode(postorder[pe]);
        int ind = inmap[node->val];
        int diff = ind - is;
        node->left = buildtree(inorder, postorder, ps, ps + diff - 1, is, ind - 1, inmap);
        node->right = buildtree(inorder, postorder, ps + diff, pe - 1, ind + 1, ie, inmap);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        int n = postorder.size();
        return buildtree(inorder, postorder, 0, n - 1, 0, n - 1, inmap);
    }
};
