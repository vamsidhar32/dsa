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
        if(root == NULL) return {};
        vector<int>ans ;
        stack<TreeNode*>st;
        //st.push(root);
        TreeNode* curr = root;  
        while(true){
            while(curr){
                st.push(curr);
                curr= curr->left;
            }
            if(curr == NULL){
                if(st.empty()) break;
                
                if(st.top()->right == NULL){
                    TreeNode* node = st.top();
                    ans.push_back(st.top()->val);
                    st.pop();
                    if(st.empty()) break;
                    while(st.top()->right == node){
                        node = st.top();
                        ans.push_back(st.top()->val);
                        st.pop();
                        if(st.empty()) break;
                    }
                    if(st.empty()) break;
                    curr = st.top()->right;
                }
                else curr = st.top()->right;
            }
        }

        return ans ;
    }
};