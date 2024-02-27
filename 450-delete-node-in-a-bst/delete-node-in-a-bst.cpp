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
    TreeNode* helper(TreeNode* curr){
        if(curr->left){
            TreeNode* leftt = curr->left;
            while(leftt->right){
                leftt = leftt->right;
            }
            leftt->right = curr->right;
            //delete curr ;
            return curr->left ;
        }
        else if (curr->right){
            TreeNode* rightt = curr->right;
            while(rightt->left){
                rightt = rightt->left;
            }
            rightt->left = curr->left ;
            //delete curr ;
            return curr->right ;
        }
        else {
            //delete curr;
            return NULL;
        }

        return NULL;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL ;
        }
        if(root->val == key){
            return helper(root);
        }
        int flag = 0 ;
        TreeNode* curr = root;
        TreeNode* prev = NULL ;
        while(curr){
            if(key > curr->val){
                prev = curr;
                curr = curr->right;
                
                flag = 1 ;
                continue;
            }

            else if(key < curr->val){
                prev = curr;
                curr = curr->left;
                
                flag = -1 ;
                continue;
            }

            else if(key == curr->val){
                if(flag == 1 ){
                    prev->right = helper(curr);
                    break;
                }
                else if (flag == -1){
                    prev->left = helper(curr);
                    break;
                }
          
            }
        }
        return root ;
    }

};