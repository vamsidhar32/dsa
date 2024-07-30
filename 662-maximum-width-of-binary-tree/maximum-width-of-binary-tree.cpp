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
        
        if(root == NULL) return 0 ;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            int first ;
            int last;
            int minn = q.front().second;
            for(int i = 0 ; i < size ; i++){
                pair<TreeNode*,int> top = q.front();
                q.pop();
                int value = top.second - minn; 
                if(i == 0) first = value;
                if(i == size -1) last = value;


                if(top.first->left) q.push({top.first->left,2LL*value+1});
                if(top.first->right) q.push({top.first->right,2LL*value+2});
                
                
            }
            ans = max(ans , last-first+1);
        }
        return ans ;
    }
};