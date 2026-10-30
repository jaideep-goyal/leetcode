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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if(root == NULL) return ans;

        if(find(to_delete.begin() , to_delete.end(), root->val) == to_delete.end()){
            ans.push_back(root);
        }
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left != NULL){
                st.push(node->left);
                int i = 0;
                while(i < to_delete.size()){
                    if(node->left->val == to_delete[i]){
                        node->left = NULL;
                        break;
                    }
                    i++;
                }
            }
            if(node->right != NULL){
                st.push(node->right);
                int i = 0;
                while(i < to_delete.size()){
                    if(node->right->val == to_delete[i]){
                        node->right = NULL;
                        break;
                    }
                    i++;
                }
            }
            int i = 0;
            while(i < to_delete.size()){
                if(node->val == to_delete[i]){
                    if(node->left != NULL){
                        ans.push_back(node->left);
                    }
                    if(node->right != NULL){
                        ans.push_back(node->right);
                    }
                    break;
                }
                i++;
            }
        }
        return ans;    
    }
};