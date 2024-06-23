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
    void preorder(TreeNode* root , map<int,multiset<int>> & verticals,int size){
        if(root == NULL) return ;

        preorder(root->left,verticals,size -1);
        preorder(root->right,verticals,size +1);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //int size = 0 ;
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>> verticals;
        //preorder(root,verticals,size);
        if(root == NULL) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int si = q.size();

            for(int i = 0 ; i <si ;i++){
                pair<TreeNode*,pair<int,int>>p = q.front();
                q.pop();
                int depth = p.second.first;
                int verti = p.second.second;
                
                verticals[verti][depth].insert(p.first->val);

                if(p.first->left) q.push({p.first->left,{depth+1,verti-1}});
                if(p.first->right) q.push({p.first->right,{depth+1,verti+1}});

            }

        }
        for(auto it :verticals){
            vector<int>temp;
            for(auto it2 : it.second){
                for(auto it3 : it2.second){
                    temp.push_back(it3);
                }
            }
            ans.push_back(temp);
        }

        return ans ;
    }
};