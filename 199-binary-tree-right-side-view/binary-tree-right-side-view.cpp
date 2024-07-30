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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ;
        if(root == NULL) return  ans ;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        int flag = 1 ;

        while(!q.empty()){
            int size = q.size();

            for(int i =0 ; i < size ; i++){
                pair<TreeNode*,int>top= q.front();
                q.pop();

                if(flag == 1){ ans.push_back(top.first->val); flag = 0;}
                if(top.first->right) q.push({top.first->right,top.second+1});
                if(top.first->left) q.push({top.first->left,top.second+1});
                
            }
            flag = 1 ;
        }


        return ans ;
    }
};