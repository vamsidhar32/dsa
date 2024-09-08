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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0 ;
        if(root == NULL) return 0 ;
        queue<pair<TreeNode*,int>>q ;
        q.push({root,0});

        while(!q.empty()){
            int k = q.size();
            int first ;
            int last ; 
            int min = q.front().second;
            for(int i =0 ;i < k ; i++){
                auto top = q.front();
                q.pop();
                TreeNode* node = top.first ;
                int index = top.second;
                if(i == 0) first = index-min ;
                if(i == k-1) last = index-min ;
                if(node->left) q.push({node->left,2*(long long)index +1} );
                if(node->right) q.push({node->right,2*(long long)index+2});
            }

            ans = max(ans,last-first+1);

        }
        return ans ;
    }
};