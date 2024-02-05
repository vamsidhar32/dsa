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
        int ans = 0;
        if(root == NULL){
            return ans ;
        }

        queue<pair<TreeNode*,long long int >> q;

        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            bool flag = true ;
            int first ;
            int ans2 ;
            for(int i =0 ; i<size ;i++){
                
                auto it = q.front() ;
                TreeNode* node = it.first ;
                int index = it.second;
                q.pop();

                if(flag){
                    flag = false ;
                    first = index ;
                }

                if( i == size-1){
                    ans2 = index-first +1 ;
                }


                if(node->left) q.push({node->left,2LL *index +1});
                if(node->right) q.push({node->right,2LL *index+2});

                
            }
            ans = max(ans,ans2);
        }

        return ans;
    }
};