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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        stack<TreeNode*>st;
        //TreeNode* temp = root ;
        TreeNode* curr = root ;
        while(true){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            //ans.push_back(curr->val);
            //curr = curr->right;
            if(curr == NULL){
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                curr = st.top()->right;
                st.pop();
            }
        }

        return ans ;

    }
};