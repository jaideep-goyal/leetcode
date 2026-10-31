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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*> mp; 
        int n = traversal.size();
        TreeNode* root = NULL;

        int count = 0;

        for(int i = 0; i < n; i++) {
        
            if(traversal[i] == '-') count++;
            else {
                int val = 0;
                while(i < n && isdigit(traversal[i])) {
                    val = val * 10 + (traversal[i] - '0');
                    i++;
                }
                i--;
                TreeNode* node = new TreeNode(val);

                if(count == 0) {
                    root = node;
                }
                else {
                    TreeNode* parent = mp[count - 1];
                    if(parent -> left == NULL) {
                        parent -> left = node;
                    }
                    else {
                        parent -> right = node;
                    }
                }

                mp[count] = node;
                count = 0;
            }
        }
        return root;
        
    }
};