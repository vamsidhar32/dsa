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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans ;
        if(root == NULL) return ans ;
        stack<TreeNode*>st;
        TreeNode* curr= root ;
        while(true){
            while(curr){
                st.push(curr);
                curr= curr->left;
            }
            if(st.empty()) break;
            if(st.top()->right) curr= st.top()->right;
            else{
                if(st.empty()) break;
                TreeNode* temp = st.top();
                ans.push_back(temp->val);
                st.pop();
                while( !st.empty() && st.top()->right == temp){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
                if(st.empty()) break;
                //curr = st.top()->right;
            }
        }
        return ans ;
    }
};