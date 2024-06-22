class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisitedNode = nullptr;
        TreeNode* curr = root;

        while (!st.empty() || curr != nullptr) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* topNode = st.top();
                // If right node doesn't exist or it is already processed
                if (topNode->right == nullptr || topNode->right == lastVisitedNode) {
                    ans.push_back(topNode->val);
                    st.pop();
                    lastVisitedNode = topNode;
                } else {
                    curr = topNode->right;
                }
            }
        }

        return ans;
    }
};
